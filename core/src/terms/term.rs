// Copyright Rob Gage 2026

use crate::environment::Symbol;
use super::Combinator;

/// A syntax term
pub enum Term<I = Symbol> {
    Application (I),
    Intrinsic (Combinator),
}