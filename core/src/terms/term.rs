// Copyright Rob Gage 2026

use crate::environment::Symbol;
use super::{
    Combinator,
    Value,
};

/// A syntax term
pub enum Term {
    Application (Symbol),
    Intrinsic (Combinator),
    Literal (Value),
}