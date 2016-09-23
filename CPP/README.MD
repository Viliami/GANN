#An Example
The following code is a minimal example of a simple genetic algorithm that maximizes the 'x' gene, a 9 bit gene, the max fitness of a 9 bit gene is 511.((2^9)-1)

##Code
```C++
float Chromosome::fitnessFunc(){
  //replace this function with your custom fitness code
  return this->getGene("x");
}

int main(int argc, char** argv){
    Chromosome chrom = Chromosome();
    chrom.addGene("x",9);
    Population pop = Population(25,chrom);
    for(int i = 0; i < 20; i++){
        pop.evolve();
        std::cout << "Fittest: " << pop.getFittest().fitness << std::endl;
        std::cout << "Average: " << pop.getAverageFitness() << std::endl;
    }
    return 0;
}
```

##Output
```
Fittest: 491
Average: 306.44
Fittest: 491
Average: 389.8
Fittest: 499
Average: 409.48
Fittest: 508
Average: 422.72
Fittest: 508
Average: 445
Fittest: 509
Average: 445.16
Fittest: 509
Average: 465.64
Fittest: 509
Average: 449.76
Fittest: 509
Average: 431.52
Fittest: 509
Average: 457.28
Fittest: 509
Average: 452.88
Fittest: 509
Average: 439.48
Fittest: 509
Average: 382.32
Fittest: 509
Average: 430.32
Fittest: 511
Average: 430.12
Fittest: 511
Average: 411.44
Fittest: 511
Average: 439.08
Fittest: 511
Average: 433.4
Fittest: 511
Average: 470.28
Fittest: 511
Average: 466.88
```
