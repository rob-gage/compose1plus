// Copyright Rob Gage 2026

use super::Term;

/// A syntax term that has not been interned into a `Namespace`
pub type RawTerm = Term<Box<str>>;