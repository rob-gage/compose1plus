// Copyright Rob Gage 2026

use crate::environment::Symbol;
use super::Term;

/// A value
pub enum Value<I = Symbol> {
    Lambda (Box<[Term<I>]>),
    Error,
    Boolean (bool),
}