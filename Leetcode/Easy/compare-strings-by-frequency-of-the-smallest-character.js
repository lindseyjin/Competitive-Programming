
/*
https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
2019-08-27
*/

/**
 * @param {string[]} queries
 * @param {string[]} words
 * @return {number[]}
 */

var calculateFrequency = function(str) {
    let count = 1;
    let smallest = str[0];
    for (let i = 1; i < str.length; ++i) {
        if (str[i] == smallest) count++;
        else if (str[i] < smallest) {
            count = 1;
            smallest = str[i];
        }
    }
    return count;
}

var numSmallerByFrequency = function(queries, words) {
    // calculate frequencies
    
    let queryFreqs = [];
    for (let q of queries) {
        queryFreqs.push(calculateFrequency(q));
    }
    let wordFreqs = [];
    for (let w of words) {
        wordFreqs.push(calculateFrequency(w));
    }

    let ans = [];
    for (let q of queryFreqs) {
        let i = 0;
        for (let w of wordFreqs) {
            if (q < w) i++;
        }
        ans.push(i);
    }
    
    return ans;
};