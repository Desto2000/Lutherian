// Copyright (C) 2023-present LutherianDB


#include <string>
#include <map>
#include <variant>
#include <vector>

class Layer {
public:
    virtual ~Layer() = default;
    virtual std::variant<int, double, std::string, bool, float> Process(const std::map<std::string, std::variant<int, double, std::string, bool, float>>& data) = 0;
};

class Optima {
public:
    Optima() = default;
    void Add(Layer* layer) { layers_.push_back(layer); }
    std::variant<int, double, std::string, bool, float> Use(std::variant<int, double, std::string, bool, float>& data) {
        std::map<std::string, std::variant<int, double, std::string, bool, float>> input_data = {{"data", data}, {"result", 0.0}};
        for (auto & layer : layers_) {
            std::variant<int, double, std::string, bool, float> result = layer->Process(input_data);
            input_data["result"] = result;
        }
        return input_data["result"];
    }
private:
    std::vector<Layer*> layers_;
};