//
// Created by norayr on 11.06.2021.
//

#ifndef SEARCHENGINE__SPELLCHECKER_HPP
#define SEARCHENGINE__SPELLCHECKER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <nuspell/dictionary.hxx>
#include <nuspell/finder.hxx>

class SpellChecker
{

private:
    std::optional<nuspell::Dictionary> englishDict;
    std::optional<nuspell::Dictionary> russianDict;

    std::vector<std::string> FilterSuggestions(std::string baseWord, std::vector<std::string> suggestions);

public:

    // Initialize all dictionaries from system
    // For install dicts run the next command : "sudo apt install hunspell-ru" ... en, tr , us, ua
    void Init();

    // Check for spells
    bool CheckQuery(const std::vector<std::string>& queryWords, std::vector<std::vector<std::string>>& suggestions);

    // Getters
    std::optional<nuspell::Dictionary> GetEnglishDict();
    std::optional<nuspell::Dictionary> GetRussianDict();

};

#endif //SEARCHENGINE__SPELLCHECKER_HPP
