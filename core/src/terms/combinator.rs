// Copyright Rob Gage 2026

/// A concatenative combinator
#[derive(Clone)]
pub enum Combinator {
    // stack combinators
    Copy,
    Drop,
    Hop,
    Swap,
    // lambda combinators
    Apply,
    Under,
    Deep,
    Compose,
    Lift,
    // arithmetic operators
    Add,
    Subtract,
    Multiply,
    Divide,
    Remainder,
    // boolean combinators
    Not,
    And,
    Or,
    Xor,
    // comparison combinators
    Equal,
    Greater,
    Less,
}

impl Combinator {

    /// Returns this `Combinator` as a `C` statement to be used in function definitions
    pub const fn as_c_statement(self) -> &'static str {
        use Combinator::*;
        match self {
            Copy        => "k_copy(context);",
            Drop        => "k_drop(context);",
            Hop         => "k_hop(context);",
            Swap        => "k_swap(context);",
            Apply       => "k_apply(context);",
            Under       => "k_under(context);",
            Deep        => "k_deep(context);",
            Compose     => "k_compose(context);",
            Lift        => "k_lift(context);",
            Add         => "k_add(context);",
            Subtract    => "k_subtract(context);",
            Multiply    => "k_multiply(context);",
            Divide      => "k_divide(context);",
            Remainder   => "k_remainder(context);",
            Not         => "k_not(context);",
            And         => "k_and(context);",
            Or          => "k_or(context);",
            Xor         => "k_xor(context);",
            Equal       => "k_equal(context);",
            Greater     => "k_greater(context);",
            Less        => "k_less(context);",
        }
    }

}