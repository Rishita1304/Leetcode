/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let ans = {};
    return function(...args) {
        let key = JSON.stringify(args)
        if(key in ans) return ans[key];
        let temp = fn(...args);
        return ans[key] = temp;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */