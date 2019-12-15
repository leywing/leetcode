//
//  074_search_a_2d_matrix.cpp
//  test
//
//  Created by ley on 2019/12/15.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if(row==0) return false;
        int col=matrix[0].size();
        if(col==0) return false;
        if(target<matrix[0][0]) return false;
        if(target==matrix[0][0]) return true;
        
        int hang;
        
        int r_max=row-1;
        //if target>matrix[r_max][0]
        int r_min=0;
        if(target==matrix[r_max][0]) return true;
        if(target>matrix[r_max][0]){
            hang=r_max;
        }else{
            while(r_max-r_min>1){
                int mid=r_min+(r_max-r_min)/2;
                //mid   mid+1
                if(matrix[mid][0]==target){
                    return true;
                }else if(matrix[mid][0]>target){
                    r_max=r_max<mid?r_max:mid;
                }else{
                    //matrix[mid][0]<target
                    r_min=r_min>mid?r_min:mid;
                }
                
                if(matrix[mid+1][0]==target){
                    return true;
                }else if(matrix[mid+1][0]>target){
                    r_max=r_max<mid+1?r_max:mid+1;
                }else{
                    //matrix[mid+1][0]<target
                    r_min=r_min>mid+1?r_min:mid+1;
                }
            }
                hang=r_min;
        }
 
        //matrix[hang][0]  < target     matrix[hang][col-1]  may = > <  target
        if(matrix[hang][col-1]==target) return true;
        else if(matrix[hang][col-1]<target) return false;
        else{
            //matrix[hang][col-1]>target
            int t_max=col-1;
            int t_min=0;
            while(t_max-t_min>1){
                int mid=t_min+(t_max-t_min)/2;
                //mid   mid+1
                if(matrix[hang][mid]==target){
                    return true;
                }else if(matrix[hang][mid]>target){
                    t_max=t_max<mid?t_max:mid;
                }else{
                    //matrix[hang][mid]<target
                    t_min=t_min>mid?t_min:mid;
                }
                
                if(matrix[hang][mid+1]==target){
                    return true;
                }else if(matrix[hang][mid+1]>target){
                    t_max=t_max<mid+1?t_max:mid+1;
                }else{
                    //matrix[hang][mid+1]<target
                    t_min=t_min>mid+1?t_min:mid+1;
                }
            }
            
            return false;
            
        }
        
        
        
    }
};
