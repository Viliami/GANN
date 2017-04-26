# GANN
GANNlib is a simple Genetic Algorithms and Neural Network library, that provides an easy to use interface for creating GAs and NNs quickly.

## Genetic Algorithms Example
Create genetic algorithms quickly and easily, here is an example of the GANNlib using 18 lines.

It currently uses roulette selection (a.k.a fitness proportionate selection) for a selection method and single point crossover as the crossover method. More crossover and selection methods will be added soon.
### Python Code Example
```python
from GANNlib import *

def fitnessFunc(self):
    return self.getGene("x")                      #simply returns the 'x' gene for the fitness function, x will be maximised

chrom = Chromosome()
chrom.addGene("x", 9)                            #adds a gene 'x' to the chromosome that is 9 bits in size
chrom.fitnessFunc = fitnessFunc                   #use custom fitness function
pop = Population(20, chrom)                       #create population of 20 of the chrom chromosomes, randomly generated

print("Fittest: "+str(pop.getFittest().fitness))  #print the fittest chromosome in the population
print("Average: "+str(pop.getAverageFitness()))   #print the average fitness across the population

for i in range(100):                              #evolve for 100 generations
    pop.evolve()                                  #evolves the population using GA
    
print("Fittest: "+str(pop.getFittest().fitness))  #print the fittest chromosome again at the end
print("Average: "+str(pop.getAverageFitness()))   #..and also print the average again
```
### Example output
```
Fittest: 433
Average: 197.05
Fittest: 511
Average: 499.0
```
511 is the max limit to the x gene since it's a 9 bit gene. (2^9-1)

# Neural networks
In progress...
