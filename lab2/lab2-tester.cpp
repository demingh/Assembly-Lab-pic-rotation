#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "lodepng.h"

using namespace std;

#ifndef GRADING_MODE
/* Once you are done implementing the functions, activate one or more of
 the following test sequences.
 Procedure to activate a single test sequence:
     replace 
          #define TEST_PART1_1 0
     with
          #define TEST_PART1_1 1
*/

#define TEST_PART1_1 1
#define TEST_PART1_2 1
#define TEST_PART1_3 1
#define TEST_PART1_4 1
#define TEST_PART1_5 1
#define TEST_PART1_6 1

#define TEST_PART2_1 1
#define TEST_PART2_2 1
#define TEST_PART2_3 1
#define TEST_PART2_4 1
#define TEST_PART2_5 1
#define TEST_PART2_6 1
#define TEST_PART2_7 1
#define TEST_PART2_8 1
#define TEST_PART2_9 1
#define TEST_PART2_10 1
#define TEST_PART2_11 1
#endif

extern char *yourName;
extern char *yourStudentID;

// These two functions should be implemented in lab2.cpp
void imageThresholding(unsigned char* buffer, int dim, unsigned char threshold);
void imageRotation(unsigned int* image, int dim, int direction);

int main() {
    int i, j;
    bool failed = false;

    vector<unsigned char> png;
    vector<unsigned char> image;
    vector<unsigned char> image2;
    unsigned int width, height;
    //lodepng::State state;
    string filename, outFilename;

    printf ("ICS 51, Lab 2, %s, %s\n\n", yourName, yourStudentID);

    // Part 1 tests
    #ifndef GRADING_MODE
    cout << endl;
    #endif
        
    #if TEST_PART1_1
      unsigned char testStr1_1[3][3] = {{  0,  30,  60},
                                        { 90, 120, 150},
                                        {180, 210, 240}};

      unsigned char exptectedStr1_1[3][3] = {{  0,   0,   0},
                                             {255, 255, 255},
                                             {255, 255, 255}};

      imageThresholding(&testStr1_1[0][0], 3, 90);
      for (i = 0; i < 3; ++i)
          for (j = 0; j < 3; ++j) {
              if (testStr1_1[i][j] != exptectedStr1_1[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 1: Test 1 failed at index: " << i << "," << j << " got: " << int(testStr1_1[i][j]) << " expected: " << int(exptectedStr1_1[i][j]) << endl;
                  #endif
                  failed = true;
              }
          }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 1: Test 1 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART1_2
      unsigned char testStr1_2[3][3] = {{  0,  30,  60 },
                                        { 90, 120, 150 },
                                        {180, 210, 240 }};

      unsigned char exptectedStr1_2[3][3] = {{  0,   0,   0},
                                             {  0,   0, 255},
                                             {255, 255, 255}};
      imageThresholding(&testStr1_2[0][0], 3, 128);
      for (i = 0; i < 3; ++i)
          for (j = 0; j < 3; ++j) {
              if (testStr1_2[i][j] != exptectedStr1_2[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 1: Test 2 failed at index: " << i << "," << j <<
                      " got: " << int(testStr1_2[i][j]) << " expected: " << int(exptectedStr1_2[i][j]) << endl;
                  #endif
                  failed = true;
              }
          }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 1: Test 2 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART1_3
      unsigned char testStr1_3[3][3] = {{   0,  30,  60},
                                        {  90, 120, 150},
                                        { 180, 210, 240}};

      unsigned char exptectedStr1_3[3][3] = {{  0,   0,   0},
                                             {  0,   0,   0},
                                             {255, 255, 255}};

      imageThresholding(&testStr1_3[0][0], 3, 180);
      for (i = 0; i < 3; ++i)
          for (j = 0; j < 3; ++j) {
              if (testStr1_3[i][j] != exptectedStr1_3[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 1: Test 3 failed at index: " << i << "," << j <<
                      " got: " << int(testStr1_3[i][j]) << " expected: " << int(exptectedStr1_3[i][j]) << endl;
                  #endif
                  failed = true;
              }
          }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 1: Test 3 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART1_4
      unsigned char testStr1_4[4][4] = {{  0,  30,  90, 120},
                                        {127,  45, 130,  60},
                                        {127, 128,   0, 130},
                                        { 27, 228, 255, 255}};
      unsigned char exptectedStr1_4[4][4] = {{0,   0,   0,   0},
                                             {0,   0, 255,   0},
                                             {0, 255,   0, 255},
                                             {0, 255, 255, 255}};
      failed = false;
      imageThresholding(&testStr1_4[0][0], 4, 128);
      for (i = 0; i < 4; ++i)
          for (j = 0; j < 4; ++j) {
              if (testStr1_4[i][j] != exptectedStr1_4[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 1: Test 4 failed at index: " << i << "," << j <<
                      " got: " <<int(testStr1_4[i][j]) << " expected: " << int(exptectedStr1_4[i][j]) << endl;
                  #endif
                  failed = true;
              }
          }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 1: Test 4 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART1_5
      unsigned char testStr1_5[4][4] = {{ 0,   30,  90, 120},
                                        { 12,  45, 130,  60},
                                        { 12, 128,  90, 190},
                                        { 27, 228, 255, 255}};
      unsigned char exptectedStr1_5[4][4] = {{0,   0,   0,   0},
                                             {0,   0,   0,   0},
                                             {0,   0,   0,   0},
                                             {0, 255, 255, 255}};
      failed = false;
      imageThresholding(&testStr1_5[0][0], 4, 200);
      for (i = 0; i < 4; ++i)
          for (j = 0; j < 4; ++j) {
              if (testStr1_5[i][j] != exptectedStr1_5[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 1: Test 5 failed at index: " << i << "," << j <<
                      " got: " <<int(testStr1_5[i][j]) << " expected: " << int(exptectedStr1_5[i][j]) << endl;
                  #endif
                  failed = true;
              }
          }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 1: Test 5 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART1_6
      filename = "lena.png";
      lodepng::decode(image, width, height, filename, LCT_GREY, 8U);
      if (image.size() == 0) {
          cerr << "lena.png not found. Make sure it exists in your solution directory." << endl;
          return -1;
      }
      assert(width == height);
      imageThresholding((unsigned char*)&image[0], width, 128);
      outFilename = "lena_binary.png";
      lodepng::encode(outFilename, image, width, height, LCT_GREY, 8U);
      image.clear();
      cout << "Check out lena_binary.png." << endl;
    #endif

    // Part 2 tests
    #ifndef GRADING_MODE
    cout << endl;
    #endif

    #if TEST_PART2_1
      unsigned int testStr2_1[3][3] = {{0x00000000, 0x10101010, 0x20202020},
                                       {0x30303030, 0x40404040, 0x50505050},
                                       {0x60606060, 0x70707070, 0x80808080}};


      unsigned int exptectedStr2_1[3][3] = {{0x20202020,  0x50505050, 0x80808080},
                                            {0x10101010,  0x40404040, 0x70707070},
                                            {0x00000000,  0x30303030, 0x60606060}};

      imageRotation(&testStr2_1[0][0], 3, -1);
      failed = false;
      for (i = 0; i < 3; ++i)
      for (j = 0; j < 3; ++j) {
          if (testStr2_1[i][j] != exptectedStr2_1[i][j]) {
              #ifndef GRADING_MODE
              cout << hex << "Part 2: Test 1 failed at index: "<< i<< ","<< j <<
                  " got(Hex): " << testStr2_1[i][j] <<" expected(Hex): " << exptectedStr2_1[i][j]<<  endl;
              #endif
              failed = true;
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 1 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_2
      unsigned int testStr2_2[4][4] = {{ 0,  1,  2,  3},
                                       { 4,  5,  6,  7},
                                       { 8,  9, 10, 11},
                                       {12, 13, 14, 15}};
      unsigned int exptectedStr2_2[4][4] = {{3, 7, 11, 15},
                                            {2, 6, 10, 14},
                                            {1, 5,  9, 13},
                                            {0, 4,  8, 12}};
      failed = false;
      imageRotation(&testStr2_2[0][0], 4, -1);
      for (i = 0; i < 4; ++i) {
          for (j = 0; j < 4; ++j) {
              if (testStr2_2[i][j]!= exptectedStr2_2[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 2: Test 2 failed at index: " << i <<","<<j<<
                      " got(Hex): " << testStr2_2[i][j] << " expected(Hex): " << exptectedStr2_2[i][j] << endl;
                  #endif
                  failed = true;
              }
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 2 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_3
      unsigned int testStr2_3[4][4] = {{10,  1,  2, 13},
                                       { 4,  5,  6,  7},
                                       { 8,  9, 10, 11},
                                       {12, 13, 14, 15}};
      unsigned int exptectedStr2_3[4][4] = {{13, 7, 11, 15},
                                            {2,  6, 10, 14},
                                            {1,  5,  9, 13},
                                            {10, 4,  8, 12}};
      failed = false;
      imageRotation(&testStr2_3[0][0], 4, -1);
      for (i = 0; i < 4; ++i) {
          for (j = 0; j < 4; ++j) {
              if (testStr2_3[i][j] != exptectedStr2_3[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 2: Test 3 failed at index: " << i << "," << j <<
                      " got(Hex): " << testStr2_3[i][j] << " expected(Hex): " << exptectedStr2_3[i][j] << endl;
                  #endif
                  failed = true;
              }
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 3 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_4
      #define DIM 11
      unsigned int testStr2_4[DIM][DIM];
      unsigned int exptectedStr2_4[DIM][DIM];
      for (i = 0; i < DIM; ++i) {
          for (j = 0; j < DIM; ++j) {
              testStr2_4[i][j] = DIM*(i+j);
              exptectedStr2_4[DIM-j-1][i] = testStr2_4[i][j];
          }
      }

      failed = false;
      imageRotation(&testStr2_4[0][0], DIM, -1);
      for (i = 0; i < DIM; ++i) {
          for (j = 0; j < DIM; ++j) {
              if (testStr2_4[i][j] != exptectedStr2_4[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 2: Test 4 failed at index: " << i << "," << j <<
                      " got(Hex): " << testStr2_4[i][j] << " expected(Hex): " << exptectedStr2_4[i][j] << endl;
                  #endif
                  failed = true;
              }
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 4 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_5
      unsigned int testStr2_5[3][3] = {{0x00000000, 0x10101010, 0x20202020},
                                       {0x30303030, 0x40404040, 0x50505050},
                                       {0x60606060, 0x70707070, 0x80808080}};


      unsigned int exptectedStr2_5[3][3] = {{0x60606060,  0x30303030, 0x00000000},
                                            {0x70707070,  0x40404040, 0x10101010},
                                            {0x80808080,  0x50505050, 0x20202020}};

      imageRotation(&testStr2_5[0][0], 3, 1);
      failed = false;
      for (i = 0; i < 3; ++i)
      for (j = 0; j < 3; ++j) {
          if (testStr2_5[i][j] != exptectedStr2_5[i][j]) {
              #ifndef GRADING_MODE
              cout << hex << "Part 2: Test 5 failed at index: "<< i<< ","<< j <<
                  " got(Hex): " << testStr2_5[i][j] <<" expected(Hex): " << exptectedStr2_5[i][j]<<  endl;
              #endif
              failed = true;
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 5 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_6
      unsigned int testStr2_6[4][4] = {{0,   1,  2,  3},
                                       {4,   5,  6,  7},
                                       {8,   9, 10, 11},
                                       {12, 13, 14, 15}};
      unsigned int exptectedStr2_6[4][4] = {{12, 8, 4, 0},
                                            {13, 9, 5, 1},
                                            {14, 10, 6, 2},
                                            {15, 11, 7, 3}};
      failed = false;
      imageRotation(&testStr2_6[0][0], 4, 1);
      for (i = 0; i < 4; ++i) {
          for (j = 0; j < 4; ++j) {
              if (testStr2_6[i][j]!= exptectedStr2_6[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 2: Test 6 failed at index: " << i <<","<<j<<
                      " got(Hex): " << testStr2_6[i][j] << " expected(Hex): " << exptectedStr2_6[i][j] << endl;
                  #endif
                  failed = true;
              }
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 6 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_7
      unsigned int testStr2_7[4][4] = {{10, 1,   2, 13},
                                       {4,  5,   6,  7},
                                       {8,  9,  10, 11},
                                       {12, 13, 14, 15}};
      unsigned int exptectedStr2_7[4][4] = {{12,  8, 4, 10},
                                            {13,  9, 5, 1 },
                                            {14, 10, 6, 2 },
                                            {15, 11, 7, 13}};
      failed = false;
      imageRotation(&testStr2_7[0][0], 4, 1);
      for (i = 0; i < 4; ++i) {
          for (j = 0; j < 4; ++j) {
              if (testStr2_7[i][j] != exptectedStr2_7[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 2: Test 7 failed at index: " << i << "," << j <<
                      " got(Hex): " << testStr2_7[i][j] << " expected(Hex): " << exptectedStr2_7[i][j] << endl;
                  #endif
                  failed = true;
              }
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 7 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_8
      #define DIM 11
      unsigned int testStr2_8[DIM][DIM];
      unsigned int exptectedStr2_8[DIM][DIM];
      for (i = 0; i < DIM; ++i) {
          for (j = 0; j < DIM; ++j) {
              testStr2_8[i][j] = DIM*(i+j);
        exptectedStr2_8[j][DIM - i - 1] = DIM*(i + j);
      }
      }

      failed = false;
      imageRotation(&testStr2_8[0][0], DIM, 1);
      for (i = 0; i < DIM; ++i) {
          for (j = 0; j < DIM; ++j) {
              if (testStr2_8[i][j] != exptectedStr2_8[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 2: Test 8 failed at index: " << i << "," << j <<
                      " got(Hex): " << testStr2_8[i][j] << " expected(Hex): " << exptectedStr2_8[i][j] << endl;
                  #endif
                  failed = true;
              }
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 8 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_9
      #define DIM 11
      unsigned int testStr2_9[DIM][DIM];
      unsigned int exptectedStr2_9[DIM][DIM];
      for (i = 0; i < DIM; ++i) {
          for (j = 0; j < DIM; ++j) {
              testStr2_9[i][j] = DIM*(i+j);
              exptectedStr2_9[i][j] = DIM*(i+j);
          }
      }

      failed = false;
      imageRotation(&testStr2_9[0][0], DIM, 0);
      for (i = 0; i < DIM; ++i) {
          for (j = 0; j < DIM; ++j) {
              if (testStr2_9[i][j] != exptectedStr2_9[i][j]) {
                  #ifndef GRADING_MODE
                  cout << "Part 2: Test 9 failed at index: " << i << "," << j <<
                      " got(Hex): " << testStr2_9[i][j] << " expected(Hex): " << exptectedStr2_9[i][j] << endl;
                  #endif
                  failed = true;
              }
          }
      }
      if (!failed)
          #ifndef GRADING_MODE
          cout << "Part 2: Test 9 passed." << endl;
          #endif
      #ifdef GRADING_MODE
      cout << !failed << endl;
      #endif
    #endif

    #if TEST_PART2_10
      // Load a RGBA png (4-Bytes per pixel)
      filename = "authoritah.png";
      lodepng::decode(image, width, height, filename, LCT_RGBA, 8U);
      if (image.size() == 0) {
          cerr << "authoritah.png not found. Make sure you have this file in your solution directory." << endl;
          return -1;
      }
      assert(width == height);
      imageRotation((unsigned int*)&image[0], width, -1);
      outFilename = "authoritah_rotated_counterclockwise.png";
      lodepng::encode(outFilename, image, width, height, LCT_RGBA, 8U);
      cout << "Check out authoritah_rotated_counterclockwise.png." << endl;
    #endif

    #if TEST_PART2_11
      // Load a RGBA png (4-Bytes per pixel)
      filename = "authoritah.png";
      lodepng::decode(image2, width, height, filename, LCT_RGBA, 8U);
      if (image2.size() == 0) {
        cerr << "authoritah.png not found. Make sure you have this file in your solution directory." << endl;
        return -1;
      }
      assert(width == height);
      imageRotation((unsigned int*)&image2[0], width, 1);
      outFilename = "authoritah_rotated_clockwise.png";
      lodepng::encode(outFilename, image2, width, height, LCT_RGBA, 8U);
      cout << "Check out authoritah_rotated_clockwise.png." << endl;
    #endif

    #ifndef GRADING_MODE
    cout << "" << endl;
    #endif
    return 0;
}