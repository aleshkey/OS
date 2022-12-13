//
// Created by alexey on 13.12.22.
//
#include "alloc.c"
#include <gtest/gtest.h>

// Mock out external dependency on mylogger.o
void Logger_log(){}

TEST(StartAddr, StartAddreses) {
    has_initialized=0;
    void* begin = sbrk(0);
    int* my_begin =(int*) my_malloc(9);                                                                                                                 my_begin-=2;
    ASSERT_EQ(begin, my_begin);
}

TEST(Content, ContentCheck){
    has_initialized=0;
    int *arr = (int*) my_malloc(sizeof (int));
    arr[0] = 10;
    ASSERT_EQ(arr[0], 10);
}

TEST (FreeContent, UsingFree){
    auto begin = sbrk(0);
    int *arr = (int*) my_malloc(sizeof (int));
    my_free(arr);
    int *end = (int*)sbrk(0);                                                                                                                                   end-=3;
    ASSERT_EQ(begin, end);
}


TEST(Content2Arr, Content2ArrCheck){
    has_initialized=0;
    int *arr1 = (int*) my_malloc(sizeof (int));
    arr1[0] = 10;
    int *arr2 = (int*) my_malloc(5* sizeof(int));
    for(int i=0;i<5; i++){
        arr2[i]=i;
    }
    ASSERT_EQ(arr1[0], 10);
}
