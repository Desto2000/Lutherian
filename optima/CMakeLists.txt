add_library(optima STATIC ../db/models/string_model.cc)
target_sources(optima
        PUBLIC
            base.cc)