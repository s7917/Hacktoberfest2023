package com.example.BinarySearch;

public class RotatedBinarySearch {
    public static void main(String[] args) {


        int [] arr = {4,5,6,7,0,1,2};
        int ans = pivotElement(arr);
        System.out.println(ans);
    }


    static int search(int[] nums, int target){
        int pivot = pivotElement(nums);

        if(pivot==-1){
            return BinarySearch(nums,target,0,nums.length-1);
        }

        if(target==nums[pivot]){
            return pivot;
        }
         if(target>=nums[0]){
            return BinarySearch(nums,target,0,pivot-1);
        }

            return BinarySearch(nums,target,pivot+1,nums.length-1);


    }


    static int pivotElement(int []arr){
        int start= 0 ;
        int end = arr.length-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(mid<end && arr[mid]>arr[mid+1]){
                return mid;
            }else if(mid>start&& arr[mid-1]>arr[mid]){
                return mid-1;
            }else if(arr[start]>arr[mid]){
                end=mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }


    static int BinarySearch(int [] arr,int target,int start,int end){


        int mid = start + (end-start)/2;

        while(start<=end){
            if(arr[mid]==target){
                return mid;
            }else if(target<arr[mid]){
                end= mid-1;
            }else{
                start = mid +1;
            }
            mid = start + (end-start)/2;
        }

        return -1;
    }

}
