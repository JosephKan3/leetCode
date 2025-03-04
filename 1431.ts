function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
  let max: number = candies[0];
  for (let i = 0; i < candies.length; i++) {
    if (candies[i] > max) {
      max = candies[i];
    }
  }

  let result: boolean[] = candies.map((amount) => {
    return(amount + extraCandies >= max)
  })

  return result;
};