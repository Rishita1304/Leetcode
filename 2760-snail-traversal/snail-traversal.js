/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(r, c) {
    if(this.length!=r*c) return [];
    let res = Array(r).fill().map(()=>[]);
    for(let j=0;j<c;j++){
        for(let i=0;i<r;i++){
            let ind = (j&1) ? r-i-1: i, 
            item = this[j*r+i];
            res[ind].push(item);
        }
    }
    return res;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */