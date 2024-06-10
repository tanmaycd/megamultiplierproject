#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void multiplier( char str1[] , int len1 , char str2[] , int len2 ){

    //creating an array dynamically to store the ans .
    //length of the array will be (len1 + len2) 
    //As the multiplication of two number of digit a and b
    //have a answer with a digit of (a+b) or (a+b-1) . 
    short int *ans = (short int*)calloc(len1 + len2 , sizeof(short int))  ;
    
    int ans_index = 0 ; //This will indicate till which index the ans is stored .

    
    for(int i=len2-1 ; i>=0 ; i--){

        //creating a temporary array which will store the data of sigle digit multiplication.
        short int *temp_arr = (short int*)calloc(len1+1 , sizeof(short int) ) ;
        int temp_index = 0 ;   

        int carry = 0 ;

        int a = ((int)(str2[i]) - 48) ; //Getting the digit from str2
                                        //which we have to multiply with str1.
        
        //Check point if the input is other than any integer.
        if((a<0) || (a>9)){
            printf("please input valid number \n") ;
            return ;
        }

        for(int j=len1-1 ; j>=0 ; j--){

            int b = ((int)(str1[j]) - 48) ; //Getting the digit from str1.
            
            //Check point if the input is other than any integer.
            if((b<0) || (b>9)){
                 printf("please input valid number \n") ;
                 return ;
            }

            int num = (a*b) ;
            num = num + carry ;
            carry = 0 ;

            if((num/10) == 0){
                //Its means it is a single digit .
                temp_arr[temp_index++] = num ;
            }
            else{
                //Its means it has two or more than two digits .
                int digit = num % 10 ;
                temp_arr[temp_index++] = digit ;
                carry = num/10 ;
            }
        }
        
        //If the carry is still there after all the addition.
        if(carry != 0){
            temp_arr[temp_index++] = carry ;
        }


        //Now we have to add the temporary array to answer array.
        int sum_carry = 0 ;
        int t = len2 - 1 - i ; //This is for shifting the temporaray array 
                               //Then add it to the answer array .

        for(int k = t  ; k<temp_index+t ; k++){

            int num = sum_carry + ans[k] + temp_arr[k-t] ; 

            if(num/10 == 0){
                //it means its a single digit .
                ans[k] = num ;
                sum_carry = 0 ;
            }
            else{
                //Its means it has two or more than two digits .
                int digit = num%10 ;
                ans[k] = digit ;
                sum_carry = num/10 ;
            }
        }

        free(temp_arr) ; //freeing the temporary array memory 
                         //because the work of temporary array is Done.

        if(sum_carry != 0){

            //The remaning sum_carry will stored in the next index of the ans.
            ans[temp_index + t] = sum_carry ;
         
            if(ans_index < (temp_index + t)){
                //updating the index of answer array .
                ans_index = temp_index + t + 1;
            }
        }
        else{
            if(ans_index < (temp_index + t)){
                //updating the index of answer array .
                 ans_index = temp_index + t ;
            }
        }
    }
    
    printf("n1*n2 = ") ;

    //Printing the answer array backward
    //As the answer stored in the answer array is 
    //in backward direction.
    for(int i=ans_index-1 ; i>=0 ; i--){
        printf("%d" , ans[i]) ;
    }

    free(ans) ; //Now freeing the answer array memory
                //because the work of answer array is done.

}

int main(){

  //creating two string to str1 and str2 to take number input as a string .
  char str1[100000] ;
  char str2[100000] ;
  
  printf("Enter the two number \n") ;
  
  printf("n1 = ") ;
  scanf("%s" , str1) ;
  
  printf("n2 = ") ;
  scanf("%s" , str2) ;
  
  //getting no of digit of the input number as length of the string is no of digit .
  int len1 = strlen(str1) ;
  int len2 = strlen(str2) ;
  

  //special case where any of the two number is zero.
  if(  (len1 == 1 && ((int)(str1[0]) - 48) == 0)  ||  (len2 == 1 && ((int)(str2[0]) - 48) == 0)  ){
        printf("n1*n2 = 0\n") ;
        return 0 ;
  }
    
  multiplier(str1 , len1 , str2 , len2 ) ;

  return 0;
}