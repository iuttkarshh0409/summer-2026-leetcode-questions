/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        const result = [];

        for (const item of obj) {
            if (Boolean(item)) {
                result.push(typeof item === "object" && item !== null
                    ? compactObject(item)
                    : item);
            }
        }

        return result;
    }

    if (obj !== null && typeof obj === "object") {
        const result = {};

        for (const key in obj) {
            if (Boolean(obj[key])) {
                result[key] = typeof obj[key] === "object"
                    ? compactObject(obj[key])
                    : obj[key];
            }
        }

        return result;
    }

    return obj;
};