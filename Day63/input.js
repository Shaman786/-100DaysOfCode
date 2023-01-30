let arr = [];
let num = prompt("Enter the number of elements to be sorted: ");

for (let i = 0; i < num; i++) {
  arr[i] = parseInt(prompt("Enter element " + (i + 1)));
}

for (let i = 0; i < num - 1; i++) {
  for (let j = 0; j < num - i - 1; j++) {
    if (arr[j] > arr[j + 1]) {
      let temp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = temp;
    }
  }
}

console.log("Sorted array: " + arr);
