import random, math

class Chromosome:
    def __init__(self):
        self.chromosome = ""
    
    def addGene(self, geneName, geneLength):
        pass
        
    def removeGene(self, geneName, geneLength):
        pass
        
    def getFitness(self):
        pass
    
    def getGene(self, geneName):
        pass

class Population:   
    def __init__(self):
        self.population = []
    
    def evolve(self):
        pass
        
    def fitnessFunction(self):
        pass
        
    def getFittest(self):
        pass
        
    def getAverageFitness(self):
        pass
        
    def evolve(self):
        pass
        
#example code
chromosome = Chromosome()
chromosome.addGene("x", 9)
chromosome.addGene("y", 9)
chromosome.addGene("rad",9)
chromosome.fitnessFunction = fitnessFunction

pop = Population(20, chromosome)
for i in range(100):
    pop = pop.evolve()
