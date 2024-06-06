/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    if(n==0) return arr;
    let newarr = [];
    for(let i=0;i<arr.length;i++){
        if(n>0 && Array.isArray(arr[i])){
            newarr.push(...flat(arr[i],n-1));
        }
        else newarr.push(arr[i]);
    }
    return newarr;
};