// Copyright Rob Gage 2026

use super::Term;

/// A value
pub enum Value {
    Lambda (Box<[Term]>),
    Error,
    Boolean (bool),
}