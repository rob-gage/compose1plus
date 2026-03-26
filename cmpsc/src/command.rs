// Copyright Rob Gage 2026

use clap::Parser;
use std::path::PathBuf;

/// A `cmpsc` command
#[derive(Parser)]
#[command(name = "cmpsc")]
pub struct Command {
    /// Source files
    #[arg(required = true)]
    pub sources: Vec<PathBuf>,
    /// Output file name
    #[arg(short, long)]
    pub output: Option<PathBuf>,
}