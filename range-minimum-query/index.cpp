//
// Created by GSU on 05.05.2019.
//
#include "index.h"

#include <iostream>
#include <bitset>
#include <bits/stdc++.h>
#include <string>


std::vector<std::string> strStdout;
const int MAXN = 10;
int A[MAXN] = {2, 4, 3, 1, 6, 7, 8, 9, 1, 7};
int M[MAXN][MAXN] = {};

int rangeMinimumQuery() {
    std::cout << "init" << std::endl;


    int RMQATrivialResult = RMQATrivial(2, 7);
    int RMQAsqrtResult = RMQAsqrt(2, 7);


    std::cout << std::endl;
    strStdout.clear();
    //strStdout.push_back("RMQATrivial(2,7) = " + std::to_string(RMQATrivialResult));
    strStdout.push_back("RMQAsqrt(2,7) = " + std::to_string(RMQAsqrtResult));
    std::cout << implode("; ", strStdout) << std::endl;

    return 0;
}

int RMQAsqrt(int start, int end) {
    int countPieces = sqrt(MAXN);
    int M[countPieces] = {};
    int stepSize = MAXN / countPieces;

    int key = 0;
    int minAValue = INT_MAX;

    for (int iPiece = 0; iPiece < countPieces - 1; iPiece++) {
        int iMstart = iPiece * stepSize;
        int iMend = iMstart + stepSize;
        int iMkey = 0;
        int iMmin = INT_MAX;
        for (int iM = iMstart; iM < iMend; iM++) {
            if (A[iM] < iMmin) iMmin = A[iM];
            iMkey = iM;
        }
        M[iPiece] = iMkey;

        if (start <= iMstart && iMend <= end) {
            if (iMmin < minAValue) minAValue = iMmin;
            key = M[iPiece];
        } else if (iMstart < start && iMend < end) {
            for (int iA = start; iA <= iMend; iA++) {
                if (A[iA] < minAValue) {
                    minAValue = A[iA];
                    key = iA;
                }
            }
        } else if (iMstart < end && iMend > end) {
            for (int iA = iMstart; iA <= end; iA++) {
                if (A[iA] < minAValue) {
                    minAValue = A[iA];
                    key = iA;
                }
            }
        }
    }

    return key;

}

int RMQATrivial(int start, int end) {
    std::cout << std::endl;


    int i, j, key;
    for (i = 0; i < MAXN; i++) {
        M[i][i] = i;
        //strStdout.push_back("M[i][j] = " + std::to_string(M[i][i]));
    }
    for (i = 0; i < MAXN; i++) {
        for (j = i + 1; j < MAXN; j++) {

            if (A[M[i][j - 1]] < A[j]) {
                M[i][j] = M[i][j - 1];
            } else {
                M[i][j] = j;
            }
            /*strStdout.clear();
            strStdout.push_back("i = " + std::to_string(i));
            strStdout.push_back("j = " + std::to_string(j));
            strStdout.push_back("M[i][j] = " + std::to_string(M[i][j]));
            std::cout << implode("; ", strStdout) << std::endl;*/

        }
    }

    key = M[i][j];

    return key;
}

std::string implode(const std::string &glue, const std::vector<std::string> &pieces) {
    std::string a;
    int leng = pieces.size();
    for (int i = 0; i < leng; i++) {
        a += pieces[i];
        if (i < (leng - 1))
            a += glue;
    }
    return a;
}
