# Smallest number of bills

> calculates the smallest number of bills you need to pay a certain amount

**Date:** 12/10/2026
**Tags:** fgets, modulo

## 🎯 Goal

What I wanted to learn: 

- to pratice fgets int input checks
- get some practice with github cli
- use modulo operator correctly

## 💡 What I Learned

- the checks that i need to do for fgets.
- first: check to see if input was fully read and if necesarry flush leftover input
- second: check input vs long boundaries for overflow etc, optional if target variable type is not long check these boundaries as a extra check
- third: check to see if any of the input was valid
- fourth: check to see if all the input was valid
- made a loop version of the function that uses an array that contains the bill values, here i learned to use the sizeof(x) and use size_t for i in loops
- this also made me use the qsort function to sort the array, learned that i can sort the array in different ways by modifying the sorting function i pass to qsort.

## 🐛 Mistakes & Fixes

- **Problem:**  when input was too many chars for the string where fgets stores what it read the leftover chars would stay in the stream and interfere with the next input
  **Fix:** check if the input was fully read with strchr and if necesarry flush the stream with getchar.

## ❓ Open Questions

- what other sorting functions can i pass to qsort? how do different sorting ways affect the speed/ outcomes of the sorting? 



