//
//  xianxingguihua_20200901.cpp
//  test
//
//  Created by ley on 2020/9/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
void pivot2(vector<vector<float>>& A,int l,int e);
void cout_A(vector<vector<float>>& A);
float simplex_ley(vector<vector<float>>& A,vector<int>& those_one,vector<int>& row_index);
bool initialize_simplex(vector<vector<float>>& A,vector<int>& NotBase, vector<int>& Base);
//终于完成！！！！！！好样的2020-09-17 1:01


void pivot2(vector<vector<float>>& A
            ,int l  // l   row
            ,int e  // e   col
             ){
                 int row=A.size();
                 int col=A[0].size();
    
                // e=e-1;
                 float master=A[l][e];
                 for(int i=0;i<col;i++){
                     if(i!=e){
                         A[l][i]=A[l][i]/master;
                     }
                 }
                 A[l][e]=1;
                 
                 for(int i=0;i<row;i++){
                     if(i!=l){
                         float slave=A[i][e];
                         for(int j=0;j<col;j++){
                             if(j!=e){
                                 A[i][j]=A[i][j]-slave*A[l][j];
                             }
                         }
                         A[i][e]=0;
                     }
                 }
}

void cout_A(vector<vector<float>>& A){
    int row=A.size();
    int col=A[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<A[i][j]<<" | ";
        }
        cout<<endl;
    }
}
void cout_vector(vector<int>& vec){
    for(auto a:vec){
        cout<<a<<" _ ";
    }
    cout<<endl;
}

bool initialize_simplex(vector<vector<float>>& A,vector<int>& NotBase, vector<int>& Base){
    
    int row=A.size();
    int col=A[0].size();
    bool okflag=true;
    for(int i=1;i<row;i++){
        if(A[i][col-1]<0){
            okflag=false;
        }
    }
    
    if(okflag){
        //it is ok
        return 1;   //1means ok
        // 0 means fail to find a answer that satisfy all the constraint
    }
    //it is not ok,need x0 to generate a good start--------------------------------
    vector<float> target_line=A[0];
    for(int j=0;j<col;j++){
        A[0][j]=0;
    }
    for(int i=0;i<row;i++){
        A[i].insert(A[i].begin()+col-1, -1);
    }
    
    NotBase.push_back(1);
    //new col
    col=A[0].size();
    //-----------------------
    //找到最小的bk pivot(k,0)即可，因为行变换，减法，导致所有的bi都大于0
    //此时再去求 max 值就可以了
    float bmin=8000000;
    int tmp_i=0;
    for(int i=1;i<row;i++){
        if(A[i][col-1]<bmin){
            tmp_i=i;
            bmin=A[i][col-1];
        }
    }
    cout<<"before bmin and x0 privot "<<" bmin: "<<bmin<<endl;
    cout_A(A);
    NotBase[Base[tmp_i]]=1;
    NotBase[col-2]=0;
    Base[tmp_i]=col-2;
    pivot2(A, tmp_i, col-2);    //pivot bmin and x0
    cout<<"----------------------------------"<<endl;
    cout_vector(NotBase);
    cout_vector(Base);
    cout<<"after"<<endl;
    cout_A(A);
    cout<<"----------------------------------"<<endl;
    
    float tmp01=-simplex_ley(A,NotBase,Base);
    cout<<"use simplex_ley to get the -x0"<<endl;
    cout_A(A);
    if(tmp01<0){
        cout<<"it fail! there is not any answer which meet the constraint"<<endl;
        return false;
    }else if(tmp01>0){
        cout<<"what?  something wrong in your program"<<endl;
        return false;
    }
    
    //check if x0 is base now
    if(NotBase[col-2]==0){
        //is base now
        for(int i=1;i<row;i++){
            if(Base[i]==col-2){
                //found it
                for(int j=0;j<col-2;j++){
                    if(NotBase[j]==1 && A[i][j]!=0){
                        NotBase[Base[i]]=1;
                        NotBase[j]=0;
                        Base[i]=j;
                        pivot2(A, i, j);    //pivot row i and col j
                        cout_vector(NotBase);
                        cout_vector(Base);
                        break;
                    }
                }
                break;
            }
        }
    }
    
    
    for(int i=0;i<row;i++){
        A[i].erase(A[i].begin()+col-2);
    }
    NotBase.pop_back();
    //new col
    cout<<"----------------------------------"<<endl;
    cout<<"after remove x0"<<endl;
    cout_vector(NotBase);
    cout_vector(Base);
    cout_A(A);
    cout<<"----------------------------------"<<endl;
    col=A[0].size();
    for(int j=0;j<col;j++){
        A[0][j]=target_line[j];
    }
    cout<<"add the target line"<<endl;
    cout_A(A);
    
    for(int j=0;j<NotBase.size();j++){
        if(NotBase[j]==1) continue;
        if(A[0][j]==0) continue;
        int the_row=1;
        for(int k=1;k<Base.size();k++){
            if(Base[k]==j){
                //found it;
                the_row=k;
                break;
            }
        }
        
        float slave=A[0][j];
        for(int j1=0;j1<col;j1++){
            if(j1!=j){
                A[0][j1]=A[0][j1]-slave*A[the_row][j1];
            }
        }
        A[0][j]=0;
    }
    
    cout<<"after the initialize_simplex"<<endl;
    cout_A(A);
    return true;
    
}


float simplex_ley(vector<vector<float>>& A,vector<int>& NotBase,vector<int>& Base){
    //direct use initialize_simplex(A);
    bool yes_or_not=initialize_simplex(A, NotBase, Base);
    if(!yes_or_not){
        return -1;
    }
    int row=A.size();
    int col=A[0].size();
    
    while(1){
        int tmp_e=INT_MAX;
        bool flag=false;
        for(int i=0;i<col-1;i++){
            if(A[0][i]>0){
                tmp_e=i;
                flag=true;
                break;
            }
        }
        
        if(!flag){
            break;
        }else{
            int tmp_l=INT_MAX;
            float tmp_min=8000000;  //.........
            for(int i=1;i<row;i++){
                if(A[i][tmp_e]>0){ //正数，这样 b[i]/A[i][tmp_e] 才会对x 有限制；负系数，就没有限制了
                    float tmp01=A[i][col-1]/A[i][tmp_e];
                    if(tmp01<tmp_min){
                        tmp_min=tmp01;
                        tmp_l=i;
                    }
                }
            }
            if(tmp_min==8000000){
                cout<<"it is infinite"<<endl;
                return -1;
            }else{
                cout<<"tmp_l: "<<tmp_l<<" tmp_e: "<<tmp_e<<endl;
                //tmp_l  will from Base to NotBase, row
                //tmp_e   will from NotBase to Base,  col
                NotBase[Base[tmp_l]]=1;
                NotBase[tmp_e]=0;
                Base[tmp_l]=tmp_e;
               
                pivot2(A, tmp_l, tmp_e);
                cout<<"----------------------------------"<<endl;
                cout_vector(NotBase);
                cout_vector(Base);
                cout_A(A);
                cout<<"----------------------------------"<<endl;
            }
        }
    }
    
    return A[0][col-1];
}


int main(){
//    vector<vector<float>> A={{3,1,2,0,0,0,0},
//        {1,1,3,1,0,0,30},
//        {2,2,5,0,1,0,24},
//        {4,1,2,0,0,1,36}
//    };

//    vector<vector<float>> A{
//        {10000,30000,0,0,0,0},
//        {2,    20,   1,0,0,1},
//        {7.5,  5,    0,1,0,1},
//        {3,    10,   0,0,1,1}
//    };
    vector<vector<float>> A={
        {-1, -1,   -1, 0,0,0},
        {-2, -7.5, -3, 1,0,-10000 },
        {-20,-5,   -10,0,1,-30000 }
    };
    vector<int> NotBase={1,1,1,0,0};
    vector<int> Base={-10000,3,4};
//    vector<vector<float>> A={
//        {2, -1, 0, 0, 0},
//        {2, -1, 1, 0, 2},
//        {1, -5, 0, 1, -4}
//    };
//    vector<int> NotBase={1,1,0,0};
//    vector<int> Base={-10000,2,3};
//
    cout_A(A);
    cout<<-simplex_ley(A,NotBase,Base)<<endl;
    //cout_A(A);
    
    return 0;
    
}
