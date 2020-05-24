/*IMPLEMENTING KNN ALGORITHM IN C++*/

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<cmath>
#include<math.h>
#include<map>
#include<bits/stdc++.h>
#include<fstream>
#include<vector>

using namespace std;

int k = 7;      //k number of nearest neighbours

/*
int cx[20] = {2, 4, 6, 1, 2, 3, 5, 6, 1, 4, 7, 5, 3, 4, 5, 3, 2, 3, 2, 4};      //x coordinates of the points
int cy[20] = {7, 3, 4, 4, 2, 6, 6, 1, 3, 4, 6, 7, 2, 5, 2, 4, 5, 3, 3, 1};      //y coordinates of the points
int clas[20] = {0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1};    //colour of the points (0 - orange, 1 - red)
*/


vector <int> cx, cy, clas;  //to store values from the file
int value;

//function to take input from the file
int inputfromcsv()
{
    //input x values
    ifstream xin;
    xin.open("xval.csv");
    if(!xin.is_open()){
        cout<<"error in opening xval.csv";
        return 1;
    }
    while(!xin.eof()){
        xin>>value;
        cx.push_back(value);
    }
    xin.close();

    //input y values
    ifstream yin;
    yin.open("yval.csv");
    if(!yin.is_open()){
        cout<<"error in opening yval.csv";
        return 1;
    }
    while(!yin.eof()){
        yin>>value;
        cy.push_back(value);
    }
    yin.close();

    //input classification of the point
    ifstream clasin;
    clasin.open("clas.csv");
    if(!clasin.is_open()){
        cout<<"error in opening clas.csv";
        return 1;
    }
    while(!clasin.eof()){
        clasin>>value;
        clas.push_back(value);
    }
    clasin.close();
    return 0;
}


int pointx = 5;     //x coordinate of our point
int pointy = 4;     //y coordinate of our point
int count0 = 0;     //to count no of orange color points near our point
int count1 = 0;     //to count no of red color points near our point
//int pointclas = 1;


//function to implement knn algorithm
//void knn(int cx[20], int cy[20], int pointx, int pointy)
void knn()     
{
    //cout<<"\nin knn";
    float dist[20];   //to store the distances
    float dist1[20];

    cx.pop_back();  //an extra element was pushed at the end of the vector
    cy.pop_back();
    clas.pop_back();

    int n = cx.size();

    //checking the vectors
    /*
    int a, b, c;
    a = n;
    cout<<"\na:"<<a<<"\n";
    for(auto m : cx)
        cout<<m<<" ";

    cout<<"\nb:"<<b<<"\n";
    for(auto m : cy)
        cout<<m<<" ";

    cout<<"\nc:"<<c<<"\n";
    for(auto m : clas)
        cout<<m<<" ";
    */

    //calculating the distance b/w the points
    //map<int, int> distmap;
    for(int i = 0; i<n; i++){
        dist[i] = sqrt(pow((cx[i] - pointx), 2) + pow((cy[i] - pointy), 2));    //calculating the distance b/w the points
        //distmap.insert( pair<int, int>(dist, clas[i]));
        dist1[i] = dist[i];
    }

    //n = 20/dist1[0];
    sort(dist1, dist1+n);      //sorting the array

    //classinfing the k nearest neighbours of the point
    cout<<"\nDISTANCE\tCOLOR";
    for(int i = 0; i<k; i++){
        for(int j =0; j<n; j++){
            if(dist1[i] == dist[j]){
                cout<<"\n"<<dist[j]<<"\t\t";
                dist[j] = 100;
                if(clas[j] == 0){
                    count0 += 1;
                    cout<<"ORANGE";
                }
                else{
                    count1 += 1;
                    cout<<"RED";
                }
                break;
            }
        }
    }

    cout<<"\nnumber of red nearest neighbours: "<<count1;
    cout<<"\nnumber of orange nearest neighbours: "<<count0;
    if(count0 > count1)
        cout<<"\n\nThe point is classified as ORANGE\n\n";
    else
        cout<<"\n\nThe point is classified as RED\n\n";

}

int main(int argc, char** argv)
{
    int f;
    cout<<"\n\nKNN implementation in c++\n";
    f = inputfromcsv();     //input from file
    if(f != 0){
        cout<<"\nprogram ended due to an error\n";
        return 1;
    }
    cout<<"Enter the X and Y coordinates of the point to be clustered:\n";
    cin>>pointx>>pointy;
    cout<<"\nvalue of 'K' is: "<<k;
    knn();  
    getch();
    return 0;
}






