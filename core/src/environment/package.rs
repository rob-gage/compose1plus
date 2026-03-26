// Copyright Rob Gage 2026

use crate::terms::Term;
use super::Symbol;
use std::collections::HashMap;

/// A module containing valid functions
pub struct Package {
    function_bodies: Box<[Box<[Term]>]>,
    exports: HashMap<Box<str>, Symbol>,
}
