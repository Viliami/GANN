#include <map>

class Chromosome{
public:
    std::string chrom;
    int length;
    int fitness;
    std::map<std::string, std::string> genes;
    Chromosome();
    Chromosome(std::string chrom);
    ~Chromosome();
    bool addGene(std::string geneName, int geneBits);
    bool removeGene(std::string geneName);
    float fitnessFunc();
    int getGene(std::string geneName);
    std::string generate();
    std::string mutateFilter(float mutationRate);

private:

};
