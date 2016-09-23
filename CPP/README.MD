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
Fittest: 110110011
Fittest: 499
Average: 405.44
Fittest: 110110011
Fittest: 499
Average: 426.48
Fittest: 111111101
Fittest: 509
Average: 461.6
Fittest: 111111101
Fittest: 509
Average: 448.56
Fittest: 111111110
Fittest: 510
Average: 480.56
Fittest: 111111110
Fittest: 510
Average: 447.8
Fittest: 111111110
Fittest: 510
Average: 451.72
Fittest: 111111110
Fittest: 510
Average: 429.04
Fittest: 111111111
Fittest: 511
Average: 449.52
Fittest: 111111111
Fittest: 511
Average: 485.28
Fittest: 111111111
Fittest: 511
Average: 486.48
Fittest: 111111111
Fittest: 511
Average: 493.56
Fittest: 111111111
Fittest: 511
Average: 483.6
Fittest: 111111111
Fittest: 511
Average: 479.92
Fittest: 111111111
Fittest: 511
Average: 472.84
Fittest: 111111111
Fittest: 511
Average: 488.52
Fittest: 111111111
Fittest: 511
Average: 456.64
Fittest: 111111111
Fittest: 511
Average: 470.84
Fittest: 111111111
Fittest: 511
Average: 497.08
Fittest: 111111111
Fittest: 511
Average: 468.48
```
