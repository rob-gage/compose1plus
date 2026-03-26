// Copyright Rob Gage 2026

use crate::terms::Term;
use super::Symbol;
use std::{
    collections::HashMap,
    fmt::{
        Result as FmtResult,
        Write,
    }
};

/// A module containing valid functions
pub struct Package {
    function_bodies: Box<[Box<[Term]>]>,
    exports: HashMap<Box<str>, Symbol>,
}

impl Package {

    /// Generates C function declarations for this `Package`
    fn generate_c_declarations<W: Write>(&self, w: &mut W) -> FmtResult {
        for i in 0..self.function_bodies.len() {
            writeln!(w, "\nvoid f{}(context_t*);", i)?;
        }
        Ok (())
    }

}