class EventEmitter {
    constructor(){
        this.events = new Map();
    }
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(event, cb) {
        if(!this.events.has(event)){
            this.events.set(event,[]);
        }
        const follower = this.events.get(event);
        follower.push(cb);
        return {
            unsubscribe: () => {
                const index = follower.indexOf(cb);
                if(index!==-1){
                    follower.splice(index,1);
                }
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(event, args = []) {
        if(!this.events.has(event)){
            return [];
        }
        let follower = this.events.get(event);
        let res = [];

        for(let follow of follower){
            res.push(follow(...args));
        }
        return res;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */