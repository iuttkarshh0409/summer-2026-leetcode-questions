/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeout;

    return function(...args) {
        clearTimeout(timeout);

        timeout = setTimeout(() => {
            fn(...args);
        }, t);
    };
};