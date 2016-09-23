#include "GANNlib.h"

unsigned int GANNlib_random_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::random_device GANNlib_random_device;
std::mt19937 GANNlib_random_generator(GANNlib_random_seed);

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm;
        stm << n ;
        return stm.str() ;
    }
}

template<typename TK, typename TV>
std::vector<TK> extract_keys(std::map<TK, TV> const& input_map){
    std::vector<TK> retval;
    for(auto const& element : input_map){
        retval.push_back(element.first);
    }
    return retval;
}

int randomNumber(int from, int to){
    std::uniform_real_distribution<> distr(from, to);
    return distr(GANNlib_random_generator);
}

float randomFloat(){
    std::uniform_real_distribution<> distr(0, 1);
    return distr(GANNlib_random_generator);
    //return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

Chromosome::Chromosome(){
    this->fitness = 0;
    this->chrom = "";
    this->length = this->chrom.length();
}

Chromosome::Chromosome(std::string chrom){
    this->chrom = chrom;
    this->fitness = 0;
    this->length = this->chrom.length();
    std::cout << "length: "<<this->length << std::endl;
}

bool Chromosome::addGene(std::string geneName, int geneBits){
    this->genes[geneName] = std::string(geneBits,'0');
    for(int i = 0; i < geneBits; i ++){
        this->chrom+="0";
    }
    //this->chrom+="0";
    this->length = this->chrom.length();
    return true;
}

bool Chromosome::removeGene(std::string geneName){
    try{
        int geneBits = genes[geneName].length();
        this->genes.erase(geneName);
        for(int i = 0; i < geneBits; i++){
            this->chrom.pop_back();
        }
        this->length = this->chrom.length();
        return true;
    }catch(int e){
        std::cout << geneName << " is not a gene." << std::endl;
        return false;
    }
}

/*float Chromosome::fitnessFunc(){
    return 0;
}*/

int Chromosome::getGene(std::string geneName){
    try{
        return strtoll(this->genes[geneName].c_str(), NULL, 2);
    }catch(int e){
        std::cout << geneName << " is not a gene." << std::endl;
        return 0;
    }
}

std::string Chromosome::generate(){
    //TODO: update this function to update the genes map
    this->chrom = "";
    for(int i = 0; i < this->length; i++){
        this->chrom+=patch::to_string(randomNumber(0,2));
    }
    this->updateGenes();
    this->fitness = this->fitnessFunc();
    return this->chrom;
}


void Chromosome::updateGenes(){
    std::vector<std::string> keys = extract_keys(this->genes);
    int cursor = 0;
    for(int i = 0; i < keys.size(); i++){
        std::string key = keys[i];
        int bitSize = this->genes[key].length();
        this->genes[key] = this->chrom.substr(cursor,cursor+bitSize);
        //std::cout << key << ": " << this->genes[key] << std::endl;
        cursor+=bitSize;
    }
}

std::string Chromosome::mutateFilter(float mutationRate){
    std::string chrom = "";
    //std::cout << "og: " << this->chrom << std::endl;
    for(int i = 0; i < (signed int)this->chrom.length(); i++){
        char bit = this->chrom[i];
        //std::cout << bit << std::endl;
        float rand = randomFloat();
        //std::cout << rand << " " << (rand < mutationRate) << mutationRate << std::endl;
        if(rand < mutationRate){
            if(bit == '0'){
                chrom+='1';
            }else{
                chrom+='0';
            }
            //std::cout << chrom << std::endl;
        }else{
            chrom+=bit;
        }
    }
    this->chrom = chrom;
    //std::cout << "ng: " << this->chrom << std::endl;
    return this->chrom;
}

Population::Population(int size, Chromosome chromType){
    for(int i = 0; i < size; i++){
        Chromosome chrom = Chromosome();
        std::vector<std::string> keys = extract_keys(chromType.genes);
        for(int j = 0; j < keys.size(); j++){
            std::string key = keys[j];
            chrom.addGene(key, chromType.genes[key].length());
        }
        chrom.generate();
        this->population.push_back(chrom);
    }
    this->size = size;
    this->mutationRate = 0.02;
    this->crossoverRate = 0.7;
    this->chromType = chromType;
    this->eliteClones = 1;
}

Chromosome Population::randomChromosome(){
    return this->population[randomNumber(0,this->size)];
}

Chromosome Population::getFittest(int n=0){
    this->size = this->population.size();
    float maxFitness = -1;
    Chromosome fittest = Chromosome();
    for(int i = 0; i < size; i++){
        Chromosome chrom = this->population[i];
        if(chrom.fitness > maxFitness){
            maxFitness = chrom.fitness;
            fittest = chrom;
        }
    }
    return fittest;
}

float Population::getAverageFitness(){
    this->size = this->population.size();
    float fitnessSum = 0;
    for(int i = 0; i  < this->size; i++){
        fitnessSum += this->population[i].fitness;
    }
    return fitnessSum/this->size;
}

Chromosome Population::rouletteSelect(){
    this->size = this->population.size();
    float maxFitness = this->getFittest().fitness;
    if(this->size <= 0){
        return Chromosome();
    }else if(this->size == 1 || maxFitness == 0){
        return this->population[0];
    }
    while(true){
        Chromosome chrom = this->randomChromosome();
        if(randomFloat() < chrom.fitnessFunc()/maxFitness){
            return chrom;
        }
    }
}

Chromosome Population::crossover(Chromosome c1, Chromosome c2){
    std::string gene1 = c1.chrom;
    std::string gene2 = c2.chrom;
    int splitIndex = randomNumber(1,gene1.length()-2);
    //std::cout << "Split index: " << splitIndex << std::endl;
    std::string combinedGene = gene1.substr(0,splitIndex)+gene2.substr(splitIndex,std::string::npos);
    Chromosome chrom = c1;
    chrom.chrom = combinedGene;
    chrom.updateGenes();
    chrom.fitness = chrom.fitnessFunc();
    return chrom;
}

std::vector<Chromosome> Population::evolve(){
    std::vector<Chromosome> nextGen;
    for(int i = 0; i < this->eliteClones; i++){
        nextGen.push_back(this->getFittest(i));
    }
    for(int i = 0; i < this->size-this->eliteClones; i++){
        Chromosome c1 = this->rouletteSelect();
        if(randomFloat() < this->crossoverRate){
            Chromosome c2 = this->rouletteSelect();
            c1 = this->crossover(c1,c2);
        }
        c1.mutateFilter(this->mutationRate);
        c1.fitness = c1.fitnessFunc();
        nextGen.push_back(c1);
    }
    this->population = nextGen;
    return this->population;
}

float Chromosome::fitnessFunc(){
    //return this->getGene("x");
    return 0;
}
