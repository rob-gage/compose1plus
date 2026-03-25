// Copyright Rob Gage 2026

use clap::{
    Parser,
    Subcommand as ClapSubcommand,
};

/// A `cmpstr` command
#[derive(Parser)]
#[command(name = "cmpstr")]
#[command(about = "Compose build tool and package manager", long_about = None)]
pub struct Command {
    #[command(subcommand)]
    pub command: Subcommand,
}

/// A `cmpstr` subcommand
#[derive(ClapSubcommand)]
pub enum Subcommand {
    /// Build the current project
    Build { },

    /// Run the current project
    Run { },

    /// Install the current project or a package
    Install { },

    /// Import a dependency into the project
    Import { },
}