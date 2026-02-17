let square = (n) => {
  console.log("Running square...")
  return n*n
}

console.log(square(4))

setTimeout(square, 1000)