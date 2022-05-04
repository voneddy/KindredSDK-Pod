#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "model_base_impl.h"

#include "tt_defs.h"

class ModelImpl : public ModelBaseImpl
{
private:
public:
    void loadEmojiPrediction(const std::string& emoji_path, const std::string &emoji_dictionary_path) {}
    void loadEmojiPrediction(const std::string& emoji_path, const char* dataDict, size_t lengthDict) {}
    void loadEmojiPrediction(const char* dataModel, size_t lengthModel, const char* dataDict, size_t lengthDict) {}

    EmojiPredictionOutput forwardEmojiPrediction(const std::vector<std::string>& context, double mojiPredictionThreshold) {return {};}
};

#endif // MODELIMPL_H
