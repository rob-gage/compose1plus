// Copyright Rob Gage 2026

use crate::terms::Term;
use super::Symbol;
use std::collections::HashMap;

/// A namespace that interns and stores function definitions
pub struct Namespace {
    function_bodies: Vec<Box<[Term]>>,
    names: HashMap<String, Symbol>,
}

impl Namespace {



}