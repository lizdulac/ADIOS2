// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file parser.h
 ** Define the adios2::detail::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
// "%code requires" blocks.
#line 11 "../parser.y"

  #include <tuple>
  #include <vector>
  #include <string>
  namespace adios2
  {
    namespace detail
    {
      class ASTDriver;
    }
  }

#line 62 "parser.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 6 "../parser.y"
namespace adios2 { namespace detail {
#line 203 "parser.h"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // argument_expression_list
      char dummy1[sizeof (int)];

      // IDENTIFIER
      // CONSTANT
      // STRING_LITERAL
      // SIZEOF
      // PTR_OP
      // INC_OP
      // DEC_OP
      // LEFT_OP
      // RIGHT_OP
      // LE_OP
      // GE_OP
      // EQ_OP
      // NE_OP
      // AND_OP
      // OR_OP
      // MUL_ASSIGN
      // DIV_ASSIGN
      // MOD_ASSIGN
      // ADD_ASSIGN
      // SUB_ASSIGN
      // LEFT_ASSIGN
      // RIGHT_ASSIGN
      // AND_ASSIGN
      // XOR_ASSIGN
      // OR_ASSIGN
      // TYPE_NAME
      // SEMICOLON
      // LBRACE
      // RBRACE
      // COMMA
      // COLON
      // ASSIGN
      // LPAREN
      // RPAREN
      // LBRACKET
      // RBRACKET
      // PERIOD
      // AMPERSAND
      // EXCLAMATION
      // TILDE
      // MINUS_OP
      // ADD_OP
      // MULT_OP
      // DIV_OP
      // MOD_OP
      // LT_OP
      // GT_OP
      // EXP_OP
      // PIPE
      // QUESTION
      // ALIAS_OP
      // TYPEDEF
      // EXTERN
      // STATIC
      // AUTO
      // REGISTER
      // INLINE
      // RESTRICT
      // CHAR
      // SHORT
      // INT
      // LONG
      // SIGNED
      // UNSIGNED
      // FLOAT
      // DOUBLE
      // CONST
      // VOLATILE
      // VOID
      // BOOL
      // COMPLEX
      // IMAGINARY
      // STRUCT
      // UNION
      // ENUM
      // ELLIPSIS
      // CASE
      // DEFAULT
      // IF
      // ELSE
      // SWITCH
      // WHILE
      // DO
      // FOR
      // GOTO
      // CONTINUE
      // BREAK
      // RETURN
      char dummy2[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOK_YYEMPTY = -2,
    TOK_YYEOF = 0,                 // "end of file"
    TOK_YYerror = 1,               // error
    TOK_YYUNDEF = 2,               // "invalid token"
    TOK_IDENTIFIER = 3,            // IDENTIFIER
    TOK_CONSTANT = 4,              // CONSTANT
    TOK_STRING_LITERAL = 5,        // STRING_LITERAL
    TOK_SIZEOF = 6,                // SIZEOF
    TOK_PTR_OP = 7,                // PTR_OP
    TOK_INC_OP = 8,                // INC_OP
    TOK_DEC_OP = 9,                // DEC_OP
    TOK_LEFT_OP = 10,              // LEFT_OP
    TOK_RIGHT_OP = 11,             // RIGHT_OP
    TOK_LE_OP = 12,                // LE_OP
    TOK_GE_OP = 13,                // GE_OP
    TOK_EQ_OP = 14,                // EQ_OP
    TOK_NE_OP = 15,                // NE_OP
    TOK_AND_OP = 16,               // AND_OP
    TOK_OR_OP = 17,                // OR_OP
    TOK_MUL_ASSIGN = 18,           // MUL_ASSIGN
    TOK_DIV_ASSIGN = 19,           // DIV_ASSIGN
    TOK_MOD_ASSIGN = 20,           // MOD_ASSIGN
    TOK_ADD_ASSIGN = 21,           // ADD_ASSIGN
    TOK_SUB_ASSIGN = 22,           // SUB_ASSIGN
    TOK_LEFT_ASSIGN = 23,          // LEFT_ASSIGN
    TOK_RIGHT_ASSIGN = 24,         // RIGHT_ASSIGN
    TOK_AND_ASSIGN = 25,           // AND_ASSIGN
    TOK_XOR_ASSIGN = 26,           // XOR_ASSIGN
    TOK_OR_ASSIGN = 27,            // OR_ASSIGN
    TOK_TYPE_NAME = 28,            // TYPE_NAME
    TOK_SEMICOLON = 29,            // SEMICOLON
    TOK_LBRACE = 30,               // LBRACE
    TOK_RBRACE = 31,               // RBRACE
    TOK_COMMA = 32,                // COMMA
    TOK_COLON = 33,                // COLON
    TOK_ASSIGN = 34,               // ASSIGN
    TOK_LPAREN = 35,               // LPAREN
    TOK_RPAREN = 36,               // RPAREN
    TOK_LBRACKET = 37,             // LBRACKET
    TOK_RBRACKET = 38,             // RBRACKET
    TOK_PERIOD = 39,               // PERIOD
    TOK_AMPERSAND = 40,            // AMPERSAND
    TOK_EXCLAMATION = 41,          // EXCLAMATION
    TOK_TILDE = 42,                // TILDE
    TOK_MINUS_OP = 43,             // MINUS_OP
    TOK_ADD_OP = 44,               // ADD_OP
    TOK_MULT_OP = 45,              // MULT_OP
    TOK_DIV_OP = 46,               // DIV_OP
    TOK_MOD_OP = 47,               // MOD_OP
    TOK_LT_OP = 48,                // LT_OP
    TOK_GT_OP = 49,                // GT_OP
    TOK_EXP_OP = 50,               // EXP_OP
    TOK_PIPE = 51,                 // PIPE
    TOK_QUESTION = 52,             // QUESTION
    TOK_ALIAS_OP = 53,             // ALIAS_OP
    TOK_TYPEDEF = 54,              // TYPEDEF
    TOK_EXTERN = 55,               // EXTERN
    TOK_STATIC = 56,               // STATIC
    TOK_AUTO = 57,                 // AUTO
    TOK_REGISTER = 58,             // REGISTER
    TOK_INLINE = 59,               // INLINE
    TOK_RESTRICT = 60,             // RESTRICT
    TOK_CHAR = 61,                 // CHAR
    TOK_SHORT = 62,                // SHORT
    TOK_INT = 63,                  // INT
    TOK_LONG = 64,                 // LONG
    TOK_SIGNED = 65,               // SIGNED
    TOK_UNSIGNED = 66,             // UNSIGNED
    TOK_FLOAT = 67,                // FLOAT
    TOK_DOUBLE = 68,               // DOUBLE
    TOK_CONST = 69,                // CONST
    TOK_VOLATILE = 70,             // VOLATILE
    TOK_VOID = 71,                 // VOID
    TOK_BOOL = 72,                 // BOOL
    TOK_COMPLEX = 73,              // COMPLEX
    TOK_IMAGINARY = 74,            // IMAGINARY
    TOK_STRUCT = 75,               // STRUCT
    TOK_UNION = 76,                // UNION
    TOK_ENUM = 77,                 // ENUM
    TOK_ELLIPSIS = 78,             // ELLIPSIS
    TOK_CASE = 79,                 // CASE
    TOK_DEFAULT = 80,              // DEFAULT
    TOK_IF = 81,                   // IF
    TOK_ELSE = 82,                 // ELSE
    TOK_SWITCH = 83,               // SWITCH
    TOK_WHILE = 84,                // WHILE
    TOK_DO = 85,                   // DO
    TOK_FOR = 86,                  // FOR
    TOK_GOTO = 87,                 // GOTO
    TOK_CONTINUE = 88,             // CONTINUE
    TOK_BREAK = 89,                // BREAK
    TOK_RETURN = 90                // RETURN
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 91, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_IDENTIFIER = 3,                        // IDENTIFIER
        S_CONSTANT = 4,                          // CONSTANT
        S_STRING_LITERAL = 5,                    // STRING_LITERAL
        S_SIZEOF = 6,                            // SIZEOF
        S_PTR_OP = 7,                            // PTR_OP
        S_INC_OP = 8,                            // INC_OP
        S_DEC_OP = 9,                            // DEC_OP
        S_LEFT_OP = 10,                          // LEFT_OP
        S_RIGHT_OP = 11,                         // RIGHT_OP
        S_LE_OP = 12,                            // LE_OP
        S_GE_OP = 13,                            // GE_OP
        S_EQ_OP = 14,                            // EQ_OP
        S_NE_OP = 15,                            // NE_OP
        S_AND_OP = 16,                           // AND_OP
        S_OR_OP = 17,                            // OR_OP
        S_MUL_ASSIGN = 18,                       // MUL_ASSIGN
        S_DIV_ASSIGN = 19,                       // DIV_ASSIGN
        S_MOD_ASSIGN = 20,                       // MOD_ASSIGN
        S_ADD_ASSIGN = 21,                       // ADD_ASSIGN
        S_SUB_ASSIGN = 22,                       // SUB_ASSIGN
        S_LEFT_ASSIGN = 23,                      // LEFT_ASSIGN
        S_RIGHT_ASSIGN = 24,                     // RIGHT_ASSIGN
        S_AND_ASSIGN = 25,                       // AND_ASSIGN
        S_XOR_ASSIGN = 26,                       // XOR_ASSIGN
        S_OR_ASSIGN = 27,                        // OR_ASSIGN
        S_TYPE_NAME = 28,                        // TYPE_NAME
        S_SEMICOLON = 29,                        // SEMICOLON
        S_LBRACE = 30,                           // LBRACE
        S_RBRACE = 31,                           // RBRACE
        S_COMMA = 32,                            // COMMA
        S_COLON = 33,                            // COLON
        S_ASSIGN = 34,                           // ASSIGN
        S_LPAREN = 35,                           // LPAREN
        S_RPAREN = 36,                           // RPAREN
        S_LBRACKET = 37,                         // LBRACKET
        S_RBRACKET = 38,                         // RBRACKET
        S_PERIOD = 39,                           // PERIOD
        S_AMPERSAND = 40,                        // AMPERSAND
        S_EXCLAMATION = 41,                      // EXCLAMATION
        S_TILDE = 42,                            // TILDE
        S_MINUS_OP = 43,                         // MINUS_OP
        S_ADD_OP = 44,                           // ADD_OP
        S_MULT_OP = 45,                          // MULT_OP
        S_DIV_OP = 46,                           // DIV_OP
        S_MOD_OP = 47,                           // MOD_OP
        S_LT_OP = 48,                            // LT_OP
        S_GT_OP = 49,                            // GT_OP
        S_EXP_OP = 50,                           // EXP_OP
        S_PIPE = 51,                             // PIPE
        S_QUESTION = 52,                         // QUESTION
        S_ALIAS_OP = 53,                         // ALIAS_OP
        S_TYPEDEF = 54,                          // TYPEDEF
        S_EXTERN = 55,                           // EXTERN
        S_STATIC = 56,                           // STATIC
        S_AUTO = 57,                             // AUTO
        S_REGISTER = 58,                         // REGISTER
        S_INLINE = 59,                           // INLINE
        S_RESTRICT = 60,                         // RESTRICT
        S_CHAR = 61,                             // CHAR
        S_SHORT = 62,                            // SHORT
        S_INT = 63,                              // INT
        S_LONG = 64,                             // LONG
        S_SIGNED = 65,                           // SIGNED
        S_UNSIGNED = 66,                         // UNSIGNED
        S_FLOAT = 67,                            // FLOAT
        S_DOUBLE = 68,                           // DOUBLE
        S_CONST = 69,                            // CONST
        S_VOLATILE = 70,                         // VOLATILE
        S_VOID = 71,                             // VOID
        S_BOOL = 72,                             // BOOL
        S_COMPLEX = 73,                          // COMPLEX
        S_IMAGINARY = 74,                        // IMAGINARY
        S_STRUCT = 75,                           // STRUCT
        S_UNION = 76,                            // UNION
        S_ENUM = 77,                             // ENUM
        S_ELLIPSIS = 78,                         // ELLIPSIS
        S_CASE = 79,                             // CASE
        S_DEFAULT = 80,                          // DEFAULT
        S_IF = 81,                               // IF
        S_ELSE = 82,                             // ELSE
        S_SWITCH = 83,                           // SWITCH
        S_WHILE = 84,                            // WHILE
        S_DO = 85,                               // DO
        S_FOR = 86,                              // FOR
        S_GOTO = 87,                             // GOTO
        S_CONTINUE = 88,                         // CONTINUE
        S_BREAK = 89,                            // BREAK
        S_RETURN = 90,                           // RETURN
        S_YYACCEPT = 91,                         // $accept
        S_primary_expression = 92,               // primary_expression
        S_postfix_expression = 93,               // postfix_expression
        S_argument_expression_list = 94,         // argument_expression_list
        S_unary_expression = 95,                 // unary_expression
        S_cast_expression = 96,                  // cast_expression
        S_multiplicative_expression = 97,        // multiplicative_expression
        S_additive_expression = 98,              // additive_expression
        S_shift_expression = 99,                 // shift_expression
        S_relational_expression = 100,           // relational_expression
        S_equality_expression = 101,             // equality_expression
        S_and_expression = 102,                  // and_expression
        S_exclusive_or_expression = 103,         // exclusive_or_expression
        S_inclusive_or_expression = 104,         // inclusive_or_expression
        S_logical_and_expression = 105,          // logical_and_expression
        S_logical_or_expression = 106,           // logical_or_expression
        S_conditional_expression = 107,          // conditional_expression
        S_assignment_expression = 108,           // assignment_expression
        S_expression = 109,                      // expression
        S_assignment = 110,                      // assignment
        S_start_node = 111                       // start_node
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_SIZEOF: // SIZEOF
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_DEC_OP: // DEC_OP
      case symbol_kind::S_LEFT_OP: // LEFT_OP
      case symbol_kind::S_RIGHT_OP: // RIGHT_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_MUL_ASSIGN: // MUL_ASSIGN
      case symbol_kind::S_DIV_ASSIGN: // DIV_ASSIGN
      case symbol_kind::S_MOD_ASSIGN: // MOD_ASSIGN
      case symbol_kind::S_ADD_ASSIGN: // ADD_ASSIGN
      case symbol_kind::S_SUB_ASSIGN: // SUB_ASSIGN
      case symbol_kind::S_LEFT_ASSIGN: // LEFT_ASSIGN
      case symbol_kind::S_RIGHT_ASSIGN: // RIGHT_ASSIGN
      case symbol_kind::S_AND_ASSIGN: // AND_ASSIGN
      case symbol_kind::S_XOR_ASSIGN: // XOR_ASSIGN
      case symbol_kind::S_OR_ASSIGN: // OR_ASSIGN
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_AMPERSAND: // AMPERSAND
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_TILDE: // TILDE
      case symbol_kind::S_MINUS_OP: // MINUS_OP
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_DIV_OP: // DIV_OP
      case symbol_kind::S_MOD_OP: // MOD_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_EXP_OP: // EXP_OP
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_QUESTION: // QUESTION
      case symbol_kind::S_ALIAS_OP: // ALIAS_OP
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_EXTERN: // EXTERN
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_AUTO: // AUTO
      case symbol_kind::S_REGISTER: // REGISTER
      case symbol_kind::S_INLINE: // INLINE
      case symbol_kind::S_RESTRICT: // RESTRICT
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_SHORT: // SHORT
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LONG: // LONG
      case symbol_kind::S_SIGNED: // SIGNED
      case symbol_kind::S_UNSIGNED: // UNSIGNED
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DOUBLE: // DOUBLE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_IMAGINARY: // IMAGINARY
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_ELLIPSIS: // ELLIPSIS
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_GOTO: // GOTO
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_RETURN: // RETURN
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.template destroy< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_SIZEOF: // SIZEOF
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_DEC_OP: // DEC_OP
      case symbol_kind::S_LEFT_OP: // LEFT_OP
      case symbol_kind::S_RIGHT_OP: // RIGHT_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_MUL_ASSIGN: // MUL_ASSIGN
      case symbol_kind::S_DIV_ASSIGN: // DIV_ASSIGN
      case symbol_kind::S_MOD_ASSIGN: // MOD_ASSIGN
      case symbol_kind::S_ADD_ASSIGN: // ADD_ASSIGN
      case symbol_kind::S_SUB_ASSIGN: // SUB_ASSIGN
      case symbol_kind::S_LEFT_ASSIGN: // LEFT_ASSIGN
      case symbol_kind::S_RIGHT_ASSIGN: // RIGHT_ASSIGN
      case symbol_kind::S_AND_ASSIGN: // AND_ASSIGN
      case symbol_kind::S_XOR_ASSIGN: // XOR_ASSIGN
      case symbol_kind::S_OR_ASSIGN: // OR_ASSIGN
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_AMPERSAND: // AMPERSAND
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_TILDE: // TILDE
      case symbol_kind::S_MINUS_OP: // MINUS_OP
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_DIV_OP: // DIV_OP
      case symbol_kind::S_MOD_OP: // MOD_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_EXP_OP: // EXP_OP
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_QUESTION: // QUESTION
      case symbol_kind::S_ALIAS_OP: // ALIAS_OP
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_EXTERN: // EXTERN
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_AUTO: // AUTO
      case symbol_kind::S_REGISTER: // REGISTER
      case symbol_kind::S_INLINE: // INLINE
      case symbol_kind::S_RESTRICT: // RESTRICT
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_SHORT: // SHORT
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LONG: // LONG
      case symbol_kind::S_SIGNED: // SIGNED
      case symbol_kind::S_UNSIGNED: // UNSIGNED
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DOUBLE: // DOUBLE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_IMAGINARY: // IMAGINARY
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_ELLIPSIS: // ELLIPSIS
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_GOTO: // GOTO
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_RETURN: // RETURN
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_YYEOF
                   || (token::TOK_YYerror <= tok && tok <= token::TOK_YYUNDEF));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::TOK_IDENTIFIER <= tok && tok <= token::TOK_RETURN));
#endif
      }
    };

    /// Build a parser object.
    parser (ASTDriver& drv_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::TOK_YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::TOK_YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOK_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOK_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOK_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOK_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSTANT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CONSTANT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONSTANT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CONSTANT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRING_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZEOF (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SIZEOF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SIZEOF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SIZEOF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PTR_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PTR_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PTR_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PTR_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INC_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_INC_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INC_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_INC_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEC_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DEC_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEC_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DEC_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LEFT_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LEFT_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RIGHT_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RIGHT_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LE_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LE_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LE_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_GE_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GE_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_GE_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EQ_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQ_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EQ_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_NE_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NE_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_NE_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_AND_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_AND_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_OR_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_OR_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MUL_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MUL_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MUL_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DIV_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DIV_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MOD_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MOD_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ADD_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADD_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ADD_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SUB_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SUB_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LEFT_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LEFT_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RIGHT_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RIGHT_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_AND_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_AND_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_XOR_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_XOR_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_XOR_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_OR_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_OR_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_NAME (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TYPE_NAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE_NAME (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPE_NAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v, location_type l)
      {
        return symbol_type (token::TOK_COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (std::string v, location_type l)
      {
        return symbol_type (token::TOK_COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LBRACKET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LBRACKET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RBRACKET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RBRACKET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERIOD (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PERIOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PERIOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PERIOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMPERSAND (std::string v, location_type l)
      {
        return symbol_type (token::TOK_AMPERSAND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AMPERSAND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_AMPERSAND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAMATION (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EXCLAMATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLAMATION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EXCLAMATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TILDE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TILDE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TILDE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MINUS_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MINUS_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ADD_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADD_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ADD_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MULT_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MULT_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MULT_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DIV_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DIV_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MOD_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MOD_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LT_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LT_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LT_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_GT_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GT_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_GT_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXP_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EXP_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXP_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EXP_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIPE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PIPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PIPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PIPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTION (std::string v, location_type l)
      {
        return symbol_type (token::TOK_QUESTION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_QUESTION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_QUESTION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALIAS_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ALIAS_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ALIAS_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ALIAS_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TYPEDEF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEDEF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPEDEF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTERN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EXTERN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXTERN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EXTERN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STATIC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STATIC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STATIC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AUTO (std::string v, location_type l)
      {
        return symbol_type (token::TOK_AUTO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AUTO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_AUTO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGISTER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_REGISTER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REGISTER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_REGISTER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INLINE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_INLINE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INLINE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_INLINE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESTRICT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RESTRICT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RESTRICT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RESTRICT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHORT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SHORT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SHORT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SHORT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LONG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LONG (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LONG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIGNED (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SIGNED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SIGNED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SIGNED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNSIGNED (std::string v, location_type l)
      {
        return symbol_type (token::TOK_UNSIGNED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNSIGNED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_UNSIGNED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CONST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CONST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOLATILE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_VOLATILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VOLATILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_VOLATILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (std::string v, location_type l)
      {
        return symbol_type (token::TOK_VOID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_VOID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPLEX (std::string v, location_type l)
      {
        return symbol_type (token::TOK_COMPLEX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMPLEX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_COMPLEX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMAGINARY (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IMAGINARY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IMAGINARY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IMAGINARY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRUCT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRUCT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNION (std::string v, location_type l)
      {
        return symbol_type (token::TOK_UNION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_UNION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ENUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENUM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ENUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSIS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ELLIPSIS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELLIPSIS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ELLIPSIS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CASE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CASE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DEFAULT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEFAULT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DEFAULT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SWITCH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SWITCH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_WHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_WHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GOTO (std::string v, location_type l)
      {
        return symbol_type (token::TOK_GOTO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GOTO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_GOTO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CONTINUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CONTINUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BREAK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BREAK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RETURN, v, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 66,     ///< Last index in yytable_.
      yynnts_ = 21,  ///< Number of nonterminal symbols.
      yyfinal_ = 46 ///< Termination state number.
    };


    // User arguments.
    ASTDriver& drv;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_SIZEOF: // SIZEOF
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_DEC_OP: // DEC_OP
      case symbol_kind::S_LEFT_OP: // LEFT_OP
      case symbol_kind::S_RIGHT_OP: // RIGHT_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_MUL_ASSIGN: // MUL_ASSIGN
      case symbol_kind::S_DIV_ASSIGN: // DIV_ASSIGN
      case symbol_kind::S_MOD_ASSIGN: // MOD_ASSIGN
      case symbol_kind::S_ADD_ASSIGN: // ADD_ASSIGN
      case symbol_kind::S_SUB_ASSIGN: // SUB_ASSIGN
      case symbol_kind::S_LEFT_ASSIGN: // LEFT_ASSIGN
      case symbol_kind::S_RIGHT_ASSIGN: // RIGHT_ASSIGN
      case symbol_kind::S_AND_ASSIGN: // AND_ASSIGN
      case symbol_kind::S_XOR_ASSIGN: // XOR_ASSIGN
      case symbol_kind::S_OR_ASSIGN: // OR_ASSIGN
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_AMPERSAND: // AMPERSAND
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_TILDE: // TILDE
      case symbol_kind::S_MINUS_OP: // MINUS_OP
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_DIV_OP: // DIV_OP
      case symbol_kind::S_MOD_OP: // MOD_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_EXP_OP: // EXP_OP
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_QUESTION: // QUESTION
      case symbol_kind::S_ALIAS_OP: // ALIAS_OP
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_EXTERN: // EXTERN
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_AUTO: // AUTO
      case symbol_kind::S_REGISTER: // REGISTER
      case symbol_kind::S_INLINE: // INLINE
      case symbol_kind::S_RESTRICT: // RESTRICT
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_SHORT: // SHORT
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LONG: // LONG
      case symbol_kind::S_SIGNED: // SIGNED
      case symbol_kind::S_UNSIGNED: // UNSIGNED
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DOUBLE: // DOUBLE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_IMAGINARY: // IMAGINARY
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_ELLIPSIS: // ELLIPSIS
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_GOTO: // GOTO
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_RETURN: // RETURN
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_SIZEOF: // SIZEOF
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_DEC_OP: // DEC_OP
      case symbol_kind::S_LEFT_OP: // LEFT_OP
      case symbol_kind::S_RIGHT_OP: // RIGHT_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_MUL_ASSIGN: // MUL_ASSIGN
      case symbol_kind::S_DIV_ASSIGN: // DIV_ASSIGN
      case symbol_kind::S_MOD_ASSIGN: // MOD_ASSIGN
      case symbol_kind::S_ADD_ASSIGN: // ADD_ASSIGN
      case symbol_kind::S_SUB_ASSIGN: // SUB_ASSIGN
      case symbol_kind::S_LEFT_ASSIGN: // LEFT_ASSIGN
      case symbol_kind::S_RIGHT_ASSIGN: // RIGHT_ASSIGN
      case symbol_kind::S_AND_ASSIGN: // AND_ASSIGN
      case symbol_kind::S_XOR_ASSIGN: // XOR_ASSIGN
      case symbol_kind::S_OR_ASSIGN: // OR_ASSIGN
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_AMPERSAND: // AMPERSAND
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_TILDE: // TILDE
      case symbol_kind::S_MINUS_OP: // MINUS_OP
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_DIV_OP: // DIV_OP
      case symbol_kind::S_MOD_OP: // MOD_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_EXP_OP: // EXP_OP
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_QUESTION: // QUESTION
      case symbol_kind::S_ALIAS_OP: // ALIAS_OP
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_EXTERN: // EXTERN
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_AUTO: // AUTO
      case symbol_kind::S_REGISTER: // REGISTER
      case symbol_kind::S_INLINE: // INLINE
      case symbol_kind::S_RESTRICT: // RESTRICT
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_SHORT: // SHORT
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LONG: // LONG
      case symbol_kind::S_SIGNED: // SIGNED
      case symbol_kind::S_UNSIGNED: // UNSIGNED
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DOUBLE: // DOUBLE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_IMAGINARY: // IMAGINARY
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_ELLIPSIS: // ELLIPSIS
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_GOTO: // GOTO
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_RETURN: // RETURN
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 6 "../parser.y"
} } // adios2::detail
#line 3270 "parser.h"




#endif // !YY_YY_PARSER_H_INCLUDED
