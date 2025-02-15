file(GLOB GUMBO_PARSER_SRC
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/attribute.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/attribute.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/char_ref.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/char_ref.h

#        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/char_ref.rl
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/error.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/error.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/gumbo.h
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/insertion_mode.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/parser.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/parser.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/string_buffer.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/string_buffer.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/string_piece.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/string_piece.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tag.c
#        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tag.in

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tag_enum.h
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tag_gperf.h
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tag_sizes.h
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tag_strings.h
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/token_type.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tokenizer.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tokenizer.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/tokenizer_states.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/utf8.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/utf8.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/util.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/util.h

        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/vector.c
        ${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/src/vector.h
)