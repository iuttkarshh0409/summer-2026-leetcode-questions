/**
 * @param {number} value
 */
class Calculator {
    constructor(value) {
        this.value = value;
    }

    add(num) {
        this.value += num;
        return this;
    }

    subtract(num) {
        this.value -= num;
        return this;
    }

    multiply(num) {
        this.value *= num;
        return this;
    }

    divide(num) {
        if (num === 0) {
            throw new Error("Division by zero is not allowed");
        }

        this.value /= num;
        return this;
    }

    power(num) {
        this.value **= num;
        return this;
    }

    getResult() {
        return this.value;
    }
}