#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "GANNlib.h"
#include <SDL.h>
#include <string>

Chromosome::Chromosome(){
    this->fitness = 0;
}

Chromosome::Chromosome(std::string chrom){
    this->chrom = chrom;
    this->fitness = fitness;
}

bool Chromosome::addGene(std::string geneName, int geneBits){
    this->genes[geneName] = std::string(5,'0');
    this->chrom+="0";
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

float Chromosome::fitnessFunc(){
    return 0;
}

int Chromosome::getGene(std::string geneName){
    try{
        return strtoll(this->genes[geneName].c_str(), NULL, 2);
    }catch(int e){
        std::cout << geneName << " is not a gene." << std::endl;
        return 0;
    }
}

std::string Chromosome::generate(){
    if(this->length > 0){
        this->
    }
}

int main(int argc, char** argv){
    std::cout << "ayy lmao" << std::endl;
    return 0;
}
