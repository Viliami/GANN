from GANNlib import *

def fitnessFunc(self):
    return self.getGene("x") #simply returns the 'x' gene for the fitness function, x will be maximised

chrom = Chromosome()
chrom.addGene("x", 12)       #creates a gene 'x' that is 9 bits in size
chrom.fitnessFunc = fitnessFunc #use custom fitness function
pop = Population(20, chrom) #create population of 20 of the chrom chromosomes, randomly generated

print("Fittest: "+str(pop.getFittest().fitness)) #print the fittest chromosome in the population
print("Average: "+str(pop.getAverageFitness())) #print the average fitness across the population
for i in range(100): #evolve for 100 generations
    pop.evolve() #evolves the population using GA
print("Fittest: "+str(pop.getFittest().fitness)) #print the fittest chromosome again at the end
print("Average: "+str(pop.getAverageFitness())) #print the fittest chromosome again at the end
