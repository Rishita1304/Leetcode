/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if(obj===null || typeof obj !== 'object') return obj; // when null or non object

    if(Array.isArray(obj)) return obj.filter(Boolean).map(compactObject) // when array

    let ans = {}; // when object
    for(let key in obj){
        let val = compactObject(obj[key]);
        if(Boolean(val)) ans[key] = val;
    }
    return ans;
};