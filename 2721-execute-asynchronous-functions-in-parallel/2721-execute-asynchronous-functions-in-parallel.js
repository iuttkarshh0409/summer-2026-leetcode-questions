/**
 * @param {Function[]} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return Promise.all(functions.map(fn => fn()));
};