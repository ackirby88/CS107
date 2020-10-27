/* header files */
#include "longest_sentence.hpp"

LinkedList<std::string> *getListOfSentences(const char *filename){
    LinkedList<std::string> *list = nullptr;
    std::string line;

    std::ifstream ifs(filename);
    if (ifs.is_open() == false) {
        std::cerr << "Couldn't open file..." << std::endl;
        return nullptr;
    }

    while(std::getline(ifs,line)) {
        findAndReplaceAll(line,"...","|"); // avoid ellipsis issue
        findAndReplaceAll(line,".","|");
        findAndReplaceAll(line,"!","|");
        findAndReplaceAll(line,"?","|");
        findAndReplaceAll(line,"\" ","");

        std::istringstream p(line);
        while (std::getline(p, line, '|')) {
            list->append(&list, line);
        }
    }
    return list;
}


template <typename T>
LinkedList<T>* get_longest_sentence(LinkedList<T> *a, LinkedList<T> *b){
    //TODO: use countWords to test longest sentence
   
    //TODO: return "List" containing longest sentence
}

int main(void){
    LinkedList<std::string> *list_of_sentences = getListOfSentences("swansway-chapter1.txt");

    //TODO: Use reduceRight method -- pass in get_longest_sentence function

    //TODO: Output longest sentence and length

    return 0;
}
