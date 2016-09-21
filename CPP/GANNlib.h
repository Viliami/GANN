#include <map>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

class Chromosome{
public:
    std::string chrom;
    int length;
    float fitness;
    std::map<std::string, std::string> genes;
    Chromosome();
    Chromosome(std::string chrom);
    ~Chromosome();
    bool addGene(std::string geneName, int geneBits);
    bool removeGene(std::string geneName);
    float (*fitnessFunc)();
    int getGene(std::string geneName);
    std::string generate();
    std::string mutateFilter(float mutationRate);

private:

};

class Population{
public:
    Population(int size, Chromosome chromType);
    ~Population();
    std::vector<Chromosome> population;
    int mutationRate;
    int crossoverRate;
    int size;
    int eliteClones;
    Chromosome chromType;

    Chromosome randomChromosome(); //randomly select individual
    Chromosome rouletteSelect(); //randomly select individual with chances proportional to fitness
    Chromosome getFittest(); //get fittest individual
    std::vector<Chromosome> evolve(); //evolve the current population using GA
    Chromosome crossover(Chromosome c1, Chromosome c2); //crossover 2 individuals to create a new individual
    float getAverageFitness(); //get the average fitness of the entire population

private:

};
