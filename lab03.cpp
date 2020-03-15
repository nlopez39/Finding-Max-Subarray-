#include <iostream>
#define MIN_INT -2147483647

using namespace std;



int Find_Max_Crossing_Subarray(int* A, int low, int mid, int high){
    int left_sum = MIN_INT;// look for max in the left half 
    int sum1 = 0;                 
    //int i = 0;
    for(int i = mid; i >= low; i--){                                  //index i at mid to work down to low 
        sum1 = sum1 + A[i];                                             //forms subarray A[i..mid]
    if(sum1 > left_sum){                                              //whenever we find a sum greater then the left sum 
        left_sum = sum1;                                             //we update left_sum subarray to this subarray's sum 
        //int max_left = i;//update variable max_left to record this index i 
        }
    }
    int right_sum = MIN_INT;                                         // will look for max subarray in right half
    int sum2 = 0; 
    //int j = 0;
    for(int j = mid + 1; j <= high; j++){                                  //index j starts at mid +1  and works up to high
        sum2 = sum2 + A[j];                                                 // creates subarray of A[mid+1 ..j]
        if(sum2 > right_sum){                                              //sum values are greater than right 
            right_sum = sum2;                                              //update right sum to that sum 
             //int max_right = j; 
        }
    }
     return(left_sum + right_sum); 
   }  
   
 

int Find_Max_Subarray(int* A, int low, int high){
    int mid = 0;
    int l_sum = 0;
    int r_sum = 0;
    int c_sum = 0;
    if (high == low){
       return A[low]; //base case: only one element
    }
    else{
        mid = (low + high)/2;
        l_sum = Find_Max_Subarray(A, low, mid);                                               //recursively find max subarrays within the left subarray
        r_sum = Find_Max_Subarray(A,mid + 1, high);                                         // recursively find max subabarray within the right side 
        c_sum = Find_Max_Crossing_Subarray(A,low, mid, high);                                  //finds a maximum subarray that crosses the midpoint
    if(l_sum >= r_sum && l_sum >= c_sum){                                                           //test whether the left subarray contains a subarray with the max sum
        return l_sum;                                                                              // returns that maximum subarray
    }
    else if
        (r_sum >= l_sum && r_sum >= c_sum){                                                          // test whether the right subarray contains a subarray with the max sum
            return r_sum;                                                                             // returns the corresponding maximum array 
        }
        else{
            return c_sum;
        }
                                                                                       
    }
}

 int main(int argc, char **argv){
     int length = 0;
     cin>>length;
     int A[length];
     //int* A = new int[length];

     for(int i = 0; i <length; i++){
         cin >>A[i];

     }
     int sum = Find_Max_Subarray(A ,0,length-1);

     cout<<sum;

    

 }

