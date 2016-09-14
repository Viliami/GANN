import random, math

class Chromosome:
    def __init__(self, chrom = ""):
        self.chromosome = chrom
        self.length = len(self.chromosome)
        self.fitness = 0
        self.genes = dict()
    
    def addGene(self, geneName, geneLength):
        self.genes[geneName] = (self.length, self.length+geneLength)
        self.length+=geneLength
        self.chromosome += "0"*geneLength
        
    def removeGene(self, geneName):
        if geneName in self.genes:
            geneLength = self.genes[geneName][1]-self.genes[geneName][0]
            del self.genes[geneName]
            self.chromosome = self.chromosome[0:-geneLength] #removes out of order
            self.length -= geneLength
        else:
            print(geneName + " is not a gene")
            
    def fitnessFunc(self):
        return self.fitness
        
    def getGene(self, geneName):
        if(geneName in self.genes):
            indexes = self.genes[geneName]
        else:
            print(geneName + " is not a gene")
            return 0
        return int(self.chromosome[indexes[0]:indexes[1]],2)
        
    def generate(self):
        if(self.length > 0):
            self.chromosome = ("{0:0"+str(self.length)+"b}").format(random.getrandbits(self.length))
        else:
            self.chromosome
        chrom.fitness = self.fitnessFunc(self)
        return self.chromosome
    
    def __str__(self):
        return self.chromosome

class Population:
    def __init__(self, size, chromType):
        #self.population = [Chromosome(chromType.generate()) for i in range(size)]
        self.population = []
        for i in range(size):
            chrom = Chromosome()
            for geneName in chromType.genes.keys():
                chrom.addGene(geneName, chromType.genes[geneName][1]-chromType.genes[geneName][0])
            chrom.fitnessFunc = chromType.fitnessFunc
            chrom.generate()
            chrom.fitness = chrom.fitnessFunc(chrom)
            self.population.append(chrom)
        self.mutationRate = 0.01
        self.crossoverRate = 0.7
        self.size = size
        self.chromType = chromType
        self.eliteClones = 1
        
    def randomChromsome(self):
        return self.population[random.randrange(0,len(self.population)-1)]
        
    def rouletteSelect(self):
        maxFitness = self.getFittest().fitness
        if(len(self.population) <= 0):
            return None
        elif(len(self.population) == 1 or maxFitness == 0):
            return self.population[0]
        while True:
            chrom = self.randomChromsome() 
            if(random.random() < chrom.fitness/maxFitness):
                return chrom
        
    def getFittest(self):
        maxFitness = -1
        fittest = None
        for chrom in self.population:
            if(chrom.fitness > maxFitness):
                maxFitness = chrom.fitness
                fittest = chrom
        return fittest
        
    def getAverageFitness(self):
        fitnessSum = 0
        for chrom in self.population:
            fitnessSum += chrom.fitness
        return fitnessSum/len(self.population)
        
    def evolve(self):
        nextGen = []
        nextGen.append(self.getFittest())
        for j in range(self.size-self.eliteClones):    
            c1 = self.rouletteSelect()
            if(random.random() < self.crossoverRate):
                c2 = self.rouletteSelect()
                c1 = self.crossover(c1, c2)
            c1 = self.mutationFilter(c1)
            c1.fitness = c1.fitnessFunc()
            nextGen.append(c1)
            
    def mutationFilter(self, chromosome): 
        chrom = ""
        for bit in str(chromosome):
            if(random.random() < self.mutationRate):
                if(bit == "0"):
                    chrom+="1"
                else:
                    chrom+="0"
            else:
                chrom+=bit
        return Chromosome(chrom)
        
    def crossover(self, chrom1, chrom2):    
        gene1 = chrom1.chromosome
        gene2 = chrom2.chromosome
        splitIndex = random.randrange(1,len(gene1)-2)
        gene = gene1[:splitIndex]+gene2[splitIndex:]
        return Chromosome(gene)
        
def fitnessFunc(self):
    print(self.getGene("rad"))
    return self.getGene("rad")
