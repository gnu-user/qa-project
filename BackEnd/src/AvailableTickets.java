/**
 * Swift Ticket -- Back End
 *
 * Copyright (C) 2013, Jonathan Gillett, Daniel Smullen, and Rayan Alfaheid
 * All rights reserved.
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import com.google.common.base.Strings;

/**
 * AvailableTickets Provides methods and attributes for interacting with the
 * available tickets file in memory, and outputting to disk.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public class AvailableTickets
{
    private ArrayList<Ticket> tickets;
    private String atfFile;

    
    /**
     * Constructor for the class. Takes the path to the available tickets file, and opens it.
     * 
     * @param atfFile The path to the available tickets file. Unix-style paths only.
     * 
     * @throws FatalError Fatal errors occur under the following circumstances:
     * 			<br>The Available Tickets File is missing, or not found at the path specified.
     * @throws IOException 
     * @throws NumberFormatException 
     */
    public AvailableTickets(String atfFile) throws FatalError, NumberFormatException, IOException
    {
        this.atfFile = atfFile;
        this.tickets = new ArrayList<Ticket>();
        
        /* Parse the available tickets file */
        parse();
    }

    /**
     * Adds a Ticket object to the available tickets file collection.
     * 
     * @param ticket The Ticket object to add to the collection.
     */
    public void addTicket(Ticket ticket)
    {
        tickets.add(ticket);
    }

    /**
     * The access method for the collection of available tickets. Requires an
     * event title and a username for the seller to return the correct Ticket.
     * 
     * @param event String containing the event title for the desired Ticket.
     * @param username String containing the seller's username for the desired Ticket.
     * 
     * @return Returns the Ticket object for the specified event. If the ticket
     * was not found, the method returns null.
     */
    public Ticket getTicket(String event, String username)
    {
        for (Ticket ticket : tickets)
        {
            if (ticket.getEvent().equals(event) && ticket.getSeller().equals(username))
            {
                return ticket;
            }
        }
        
        return null;
    }

    /**
     * This method is used to determine whether a Ticket object exists in the
     * available tickets file collection. Requires that the event title and the seller's
     * username is specified to match the Ticket against.
     * 
     * @param event String containing the event title for the specified Ticket.
     * @param username String containing the seller's username for the specified Ticket.
     * 
     * @return Returns true if the ticket was found in the collection. Otherwise,
     * returns false.
     */
    public boolean hasTicket(String event, String username)
    {
        for (Ticket ticket : tickets)
        {
            if (ticket.getEvent().equals(event) && ticket.getSeller().equals(username))
            {
                return true;
            }
        }
        
        return false;
    }
    
    /**
     * Outputs the available tickets file in memory to file, over-writing
     * the old available tickets file.
     * 
     * @throws FatalError Fatal errors occur under the following circumstances:
     * 			<br>The Available Tickets File is corrupted.
     * @throws IOException 
     */
    public void write() throws IOException
    {
        BufferedWriter writer;
        String entry;
        
        File file = new File(atfFile);
 
        /* Create the file if it does not exist since parsed */
        if (!file.exists())
        {
            file.createNewFile();
        }

        writer = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
        
        /* Format each entry and write it to the file */
        for (Ticket ticket : tickets)
        {
            /* Format the event */
            entry = ticket.getEvent().replace(' ', '_');
            entry = Strings.padEnd(entry, 20, '_');
            
            /* Format the seller */
            entry += Strings.padEnd(ticket.getSeller(), 16, '_');
            
            /* Format the number of tickets */
            entry += Strings.padStart(ticket.getVolume().toString(), 3, '0') + "_";
            
            /* Format the price of tickets */
            entry += Strings.padStart(String.format("%.2f", ticket.getPrice()), 6, '0') + "\n";
            
            
            writer.write(entry);
        }
        
        /* Add the END of file identifier and close the file */
        writer.write("END_________________________________000_000.00");
        writer.close();
    }

    /**
     * Parses the available tickets file entries, matching the specified format
     * based on regular expressions.
     * 
     * @throws FatalError Fatal errors occur under the following circumstances:
     *          <br>The Current User Accounts File is missing, or not found at the path specified.
     *          <br>The current user accounts file is corrupted.
     *
     * @throws NumberFormatException
     * @throws IOException 
     */
    @SuppressWarnings("resource")
    private void parse() throws FatalError, NumberFormatException, IOException
    {
        BufferedReader reader;

        String line;
        Pattern re = Pattern.compile("^(.{1,19}?)_+_([A-Za-z0-9_]{1,15}?)_+([0-9]{3})_([0-9]{3}\\.[0-9]{2})$");
        Pattern reEnd = Pattern.compile("END_{33}0{3}_0{3}\\.0{2}");
        Matcher match;

        try
        {
            reader = new BufferedReader(new FileReader(atfFile));
        }
        catch (FileNotFoundException e1)
        {
            e1.printStackTrace();
            throw new FatalError(ExceptionCodes.ATF_NOT_FOUND, atfFile);
        }

        while ((line = reader.readLine()) != null && !reEnd.matcher(line).matches())
        {
            match = re.matcher(line);
            
            /* Add each ticket found to the list of tickets */
            if (Validate.atfEntry(line) && match.matches())
            {
                /* Replace each _ in the event title with a space character */
                String event = match.group(1).replace('_', ' ');

                /* Get the seller, volume, and price from regex groups */
                String seller = match.group(2);
                Integer volume = Integer.parseInt(match.group(3));
                Double price = Double.parseDouble(match.group(4));

                /* Add the ticket object to the array of tickets */
                tickets.add(new Ticket(event, seller, volume, price));
            }
            else
            {
                throw new FatalError(ExceptionCodes.CORRUPT_ATF, atfFile);
            }
        }
        reader.close();
    }
}