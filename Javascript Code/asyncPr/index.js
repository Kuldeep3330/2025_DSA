// // callback-hell.js

// function chaiBananeKaProcess() {
//   setTimeout(() => {
//     console.log("1. Paani ubala");

//     setTimeout(() => {
//       console.log("2. Chai patti dali");

//       setTimeout(() => {
//         console.log("3. Doodh dala");

//         setTimeout(() => {
//           console.log("4. Chai ready ☕");
//         }, 1000);

//       }, 1000);

//     }, 1000);

//   }, 1000);
// }

// chaiBananeKaProcess();


// promises.js

function paaniUbalo() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("1. Paani ubala");
    }, 1000);
  });
}

function chaiPattiDalo() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("2. Chai patti dali");
    }, 1000);
  });
}

function doodhDalo() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("3. Doodh dala");
    }, 1000);
  });
}

function chaiReady() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("4. Chai ready ☕");
    }, 1000);
  });
}

paaniUbalo()
  .then((msg) => {
    console.log(msg);
    return chaiPattiDalo();
  })
  .then((msg) => {
    console.log(msg);
    return doodhDalo();
  })
  .then((msg) => {
    console.log(msg);
    return chaiReady();
  })
  .then((msg) => {
    console.log(msg);
  })
  .catch((err) => {
    console.log("Error:", err);
  });


  // async-await.js

function delay(msg) {
  return new Promise((resolve) => {
    setTimeout(() => resolve(msg), 1000);
  });
}

async function chaiBanao() {
  try {
    console.log(await delay("1. Paani ubala"));
    console.log(await delay("2. Chai patti dali"));
    console.log(await delay("3. Doodh dala"));
    console.log(await delay("4. Chai ready ☕"));
  } catch (err) {
    console.log("Error:", err);
  }
}

chaiBanao();


//Array.prototype.myMap
Array.prototype.myMap = function(callback) {
  const result = [];    
    for (let i = 0; i < this.length; i++) {
        result.push(callback(this[i], i, this));
    }
    return result;
};
// Example usage:
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.myMap(num => num * 2);
console.log(doubled); // Output: [2, 4, 6, 8, 10]

//Array.prototype.myFilter
Array.prototype.myFilter = function(callback) {
    const result = [];
    for (let i = 0; i < this.length; i++) {
        if (callback(this[i], i, this)) {
            result.push(this[i]);
        }
    }
    return result;
};
// Example usage:
const mixedNumbers = [1, 2, 3, 4, 5, 6];
const evenNumbers = mixedNumbers.myFilter(num => num % 2 === 0);
console.log(evenNumbers); // Output: [2, 4, 6]

//Array.prototype.myReduce
Array.prototype.myReduce = function(callback, initialValue) {
    let accumulator = initialValue !== undefined ? initialValue : this[0];
    const startIndex = initialValue !== undefined ? 0 : 1;
    for (let i = startIndex; i < this.length; i++) {
        accumulator = callback(accumulator, this[i], i, this);
    }
    return accumulator;
};
// Example usage:
const sum = [1, 2, 3, 4, 5].myReduce((acc, num) => acc + num, 0);
console.log(sum); // Output: 15
