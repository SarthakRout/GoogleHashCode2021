# Google HashCode 2021

## Rank:
- Global: 1001
- India: 155

## Team:
- [Aditi Goyal](https://www.linkedin.com/in/aditi-goyal-8934641b4/)
- [Rohan Baijal](https://github.com/rohanblueboybaijal)
- [Sarthak Rout](https://github.com/SarthakRout)
- [Yatharth Goswami](https://github.com/yatharth0610)

## Points:
- A : 2,002
- B : 4,566,688
- C : 1,299,327
- D : 1,573,000
- E : 692,304
- F : 1,361,590
Total: 9,494,911

## Strategy Used:
- Measured a quantity : ratio which depicted the relative ratio of cars that are scheduled to arrive at a traffic post from a street
- Used this 'ratio' to prioritise and assign the time interval in scheduling of lights assuming a total cycle time of D, D/2, sqrt(D), 10 etc. These values can be arrived at by assuming simple relationship about the distribution of paths of cars.
- Combined it with time taken to cross the street L, to make a linear function experimenting different weights
- Also, experimented with non-linear function of 'ratio' and 'L' which were not too helpful
- Giving 1s to every street which has atleast one car at a intersection as a baseline score
- Later, also considered to give different weightage to each street from each street depending on relative ratio of L and number of streets to cover in the extended round.
- Have uploaded solutions for best score of each test case in folder solutions -- They may be same!