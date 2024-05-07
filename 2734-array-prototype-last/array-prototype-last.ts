declare global {
    interface Array<T> {
        last(): T | -1;
    }
}

Array.prototype.last = function() {
    let n = this.length - 1;
    if(n<0) return -1;
    return this[n];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */

export {};