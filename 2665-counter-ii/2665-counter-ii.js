/**
 * @param {integer} init
 * @return {{ increment: Function, decrement: Function, reset: Function }}
 */
var createCounter = function(init) {
    let current = init;

    return {
        increment: () => ++current,
        decrement: () => --current,
        reset: () => (current = init)
    };
};